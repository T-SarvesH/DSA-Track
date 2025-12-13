#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

// --- Data Structures ---

struct Point {
    int r, c;
    bool operator<(const Point& other) const {
        if (r != other.r) return r < other.r;
        return c < other.c;
    }
};

struct ShapeVariant {
    int h, w;
    vector<Point> cells; 
};

struct Shape {
    int id;
    int area;
    vector<ShapeVariant> variants;
};

// Global storage for shape definitions
map<int, Shape> all_shapes;
const int GAP_ID = 1000000; 

// --- Helpers ---

// Normalize coordinates to (0,0) based on top-leftmost cell
ShapeVariant normalize(vector<Point>& pts) {
    if (pts.empty()) return {0, 0, {}};
    sort(pts.begin(), pts.end());
    
    int r_offset = pts[0].r;
    int c_offset = pts[0].c;
    
    int max_r = 0, max_c = 0;
    for (auto& p : pts) {
        p.r -= r_offset;
        p.c -= c_offset;
        if (p.r > max_r) max_r = p.r;
        if (p.c > max_c) max_c = p.c;
    }
    return {max_r + 1, max_c + 1, pts};
}

// Pre-calculate all 8 symmetries (rotations/flips)
void generate_variants(Shape& s, const vector<string>& raw_grid) {
    if (raw_grid.empty()) return;
    vector<Point> base_points;
    for (int r = 0; r < raw_grid.size(); ++r) {
        for (int c = 0; c < raw_grid[r].size(); ++c) {
            if (raw_grid[r][c] == '#') base_points.push_back({r, c});
        }
    }
    s.area = base_points.size();

    set<vector<Point>> seen;
    vector<Point> current = base_points;
    
    for (int flip = 0; flip < 2; ++flip) {
        for (int rot = 0; rot < 4; ++rot) {
            ShapeVariant v = normalize(current);
            if (seen.find(v.cells) == seen.end()) {
                seen.insert(v.cells);
                s.variants.push_back(v);
            }
            // Rotate 90 degrees: (r, c) -> (c, -r)
            for (auto& p : current) {
                int tmp = p.r;
                p.r = p.c;
                p.c = -tmp;
            }
        }
        // Flip horizontally
        for (auto& p : current) p.c = -p.c;
    }
}

// --- Solver ---

struct Solver {
    int W, H;
    // Use char instead of bool to avoid vector<bool> proxy issues and potential corruption
    vector<vector<char>> grid; 
    map<int, int> available_counts; 
    int total_remaining_pieces;

    Solver(int w, int h, const vector<int>& p_ids) : W(w), H(h) {
        grid.assign(H, vector<char>(W, 0));
        
        long long presents_area = 0;
        for (int id : p_ids) {
            available_counts[id]++;
            presents_area += all_shapes[id].area;
        }
        total_remaining_pieces = p_ids.size();

        // Calculate slack space and add "Gap" pieces (1x1 squares)
        // This converts the problem into an Exact Cover problem
        long long slack = ((long long)W * H) - presents_area;
        if (slack > 0) {
            available_counts[GAP_ID] = (int)slack;
            total_remaining_pieces += (int)slack;
        }
    }

    // Heuristic: Always target the first empty cell (top-left)
    bool find_first_empty(int& r, int& c) {
        for (r = 0; r < H; ++r) {
            for (c = 0; c < W; ++c) {
                if (grid[r][c] == 0) return true;
            }
        }
        return false;
    }

    bool solve() {
        if (total_remaining_pieces == 0) return true;

        int r, c;
        if (!find_first_empty(r, c)) return true; // No empty cells left

        // Optimization: Try to fill this specific cell (r,c) using any available shape type.
        for (auto& [id, count] : available_counts) {
            if (count > 0) {
                const Shape& shape = all_shapes[id];
                
                for (const auto& var : shape.variants) {
                    // Quick Bounding Box Check (Optimization)
                    if (r + var.h > H || c + var.w > W) continue;

                    // Detailed Collision Check
                    // Variant is normalized to (0,0), so we check if placing it at (r,c) is valid
                    bool fits = true;
                    for (const auto& p : var.cells) {
                        int nr = r + p.r;
                        int nc = c + p.c;
                        // Strict bounds check to prevent heap corruption
                        if (nr < 0 || nr >= H || nc < 0 || nc >= W || grid[nr][nc] != 0) {
                            fits = false;
                            break;
                        }
                    }

                    if (fits) {
                        // Place Piece
                        for (const auto& p : var.cells) grid[r + p.r][c + p.c] = 1;
                        count--;
                        total_remaining_pieces--;

                        // Recurse
                        if (solve()) return true;

                        // Backtrack (Remove Piece)
                        total_remaining_pieces++;
                        count++;
                        for (const auto& p : var.cells) grid[r + p.r][c + p.c] = 0;
                    }
                }
            }
        }
        return false;
    }
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Initialize 1x1 Gap Shape manually
    Shape gap_shape;
    gap_shape.id = GAP_ID;
    gap_shape.area = 1;
    gap_shape.variants.push_back({1, 1, {{0,0}}});
    all_shapes[GAP_ID] = gap_shape;

    string line;
    vector<string> shape_buffer;
    int current_shape_id = -1;
    long long total_successes = 0;

    while (getline(cin, line)) {
        if (line.empty()) {
            if (!shape_buffer.empty() && current_shape_id != -1) {
                all_shapes[current_shape_id].id = current_shape_id;
                generate_variants(all_shapes[current_shape_id], shape_buffer);
                shape_buffer.clear();
            }
            continue;
        }

        // Detect Shape Header "N:"
        if (line.find(':') != string::npos && line.find('x') == string::npos) {
            if (!shape_buffer.empty() && current_shape_id != -1) {
                all_shapes[current_shape_id].id = current_shape_id;
                generate_variants(all_shapes[current_shape_id], shape_buffer);
                shape_buffer.clear();
            }
            current_shape_id = stoi(line.substr(0, line.find(':')));
        }
        // Detect Query "WxH: ..."
        else if (line.find("x") != string::npos && line.find(':') != string::npos) {
            // Flush any remaining shape buffer before processing query
            if (!shape_buffer.empty() && current_shape_id != -1) {
                all_shapes[current_shape_id].id = current_shape_id;
                generate_variants(all_shapes[current_shape_id], shape_buffer);
                shape_buffer.clear();
                current_shape_id = -1;
            }

            size_t col_pos = line.find(':');
            size_t x_pos = line.find('x');
            int W = stoi(line.substr(0, x_pos));
            int H = stoi(line.substr(x_pos + 1, col_pos - x_pos - 1));
            
            stringstream ss(line.substr(col_pos + 1));
            int count;
            vector<int> p_ids;
            int s_idx = 0;
            long long req_area = 0;
            
            while (ss >> count) {
                if (all_shapes.count(s_idx)) {
                    for(int k=0; k<count; ++k) {
                        p_ids.push_back(s_idx);
                        req_area += all_shapes[s_idx].area;
                    }
                }
                s_idx++;
            }

            // Pruning: If presents area > grid area, it's impossible.
            if (req_area > (long long)W * H) continue;

            Solver solver(W, H, p_ids);
            if (solver.solve()) {
                total_successes++;
            }
        }
        else {
            shape_buffer.push_back(line);
        }
    }
    
    // Process final shape if file ends without newline
    if (!shape_buffer.empty() && current_shape_id != -1) {
         generate_variants(all_shapes[current_shape_id], shape_buffer);
    }

    cout << total_successes << endl;

    return 0;
}
