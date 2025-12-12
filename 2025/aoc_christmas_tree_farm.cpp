#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

using namespace std;

struct Point {
    int r, c;
    bool operator<(const Point& other) const {
        if (r != other.r) return r < other.r;
        return c < other.c;
    }
    bool operator==(const Point& other) const {
        return r == other.r && c == other.c;
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

map<int, Shape> all_shapes;

ShapeVariant normalize(vector<Point>& pts) {
    if (pts.empty()) return {0, 0, {}};
    int min_r = pts[0].r, min_c = pts[0].c;
    for (const auto& p : pts) {
        if (p.r < min_r) min_r = p.r;
        if (p.c < min_c) min_c = p.c;
    }
    int max_r = 0, max_c = 0;
    for (auto& p : pts) {
        p.r -= min_r;
        p.c -= min_c;
        if (p.r > max_r) max_r = p.r;
        if (p.c > max_c) max_c = p.c;
    }
    sort(pts.begin(), pts.end());
    return {max_r + 1, max_c + 1, pts};
}

void generate_variants(Shape& s, const vector<string>& raw_grid) {
    vector<Point> base_points;
    for (int r = 0; r < raw_grid.size(); ++r) {
        for (int c = 0; c < raw_grid[r].size(); ++c) {
            if (raw_grid[r][c] == '#') base_points.push_back({r, c});
        }
    }
    s.area = base_points.size();

    set<vector<Point>> seen;
    vector<Point> current = base_points;
    for (int rot = 0; rot < 4; ++rot) {
        vector<Point> flipped = current;
        for (auto& p : flipped) p.c = -p.c;
        
        ShapeVariant v1 = normalize(current);
        if (seen.find(v1.cells) == seen.end()) {
            seen.insert(v1.cells);
            s.variants.push_back(v1);
        }

        ShapeVariant v2 = normalize(flipped);
        if (seen.find(v2.cells) == seen.end()) {
            seen.insert(v2.cells);
            s.variants.push_back(v2);
        }

        for (auto& p : current) {
            int tmp = p.r;
            p.r = p.c;
            p.c = -tmp;
        }
    }
}

struct Solver {
    int W, H;
    vector<vector<bool>> grid;
    vector<int> presents_to_place; 
    int total_presents;
    int min_present_area;

    Solver(int w, int h, vector<int>& p_ids) : W(w), H(h), presents_to_place(p_ids) {
        grid.assign(H, vector<bool>(W, false));
        total_presents = p_ids.size();
        min_present_area = 1e9;
        for(int id : p_ids) {
             min_present_area = min(min_present_area, all_shapes[id].area);
        }
    }

    bool check_connectivity(int required_area) {
        vector<vector<bool>> visited = grid; 
        int useful_empty_area = 0;

        for (int r = 0; r < H; ++r) {
            for (int c = 0; c < W; ++c) {
                if (!visited[r][c]) {
                    int island_size = 0;
                    queue<pair<int,int>> q;
                    q.push({r, c});
                    visited[r][c] = true;
                    island_size++;
                    
                    while(!q.empty()){
                        auto [cr, cc] = q.front();
                        q.pop();
                        
                        int dr[] = {0,0,1,-1};
                        int dc[] = {1,-1,0,0};
                        
                        for(int i=0; i<4; ++i){
                            int nr = cr + dr[i];
                            int nc = cc + dc[i];
                            if(nr>=0 && nr<H && nc>=0 && nc<W && !visited[nr][nc]){
                                visited[nr][nc] = true;
                                island_size++;
                                q.push({nr, nc});
                            }
                        }
                    }
                    
                    if (island_size >= min_present_area) {
                        useful_empty_area += island_size;
                    }
                }
            }
        }
        
        return useful_empty_area >= required_area;
    }

    bool backtrack(int idx, int prev_pos_index) {
        if (idx == total_presents) return true;

        int shape_id = presents_to_place[idx];
        const Shape& shape = all_shapes[shape_id];

        int remaining_area = 0;
        for(int i=idx; i<total_presents; ++i) remaining_area += all_shapes[presents_to_place[i]].area;

        if (!check_connectivity(remaining_area)) return false;

        int start_pos = 0;
        if (idx > 0 && presents_to_place[idx] == presents_to_place[idx-1]) {
            start_pos = prev_pos_index; 
        }

        for (int pos = start_pos; pos < W * H; ++pos) {
            int r0 = pos / W;
            int c0 = pos % W;

            if (grid[r0][c0]) continue;

            for (const auto& var : shape.variants) {
                if (r0 + var.h > H || c0 + var.w > W) continue;

                bool fits = true;
                for (const auto& p : var.cells) {
                    if (grid[r0 + p.r][c0 + p.c]) {
                        fits = false;
                        break;
                    }
                }

                if (fits) {
                    for (const auto& p : var.cells) grid[r0 + p.r][c0 + p.c] = true;
                    if (backtrack(idx + 1, pos)) return true;
                    for (const auto& p : var.cells) grid[r0 + p.r][c0 + p.c] = false;
                }
            }
        }

        return false;
    }
};

int main() {
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

        if (line.find(':') != string::npos && line.find('x') == string::npos) {
            if (!shape_buffer.empty() && current_shape_id != -1) {
                all_shapes[current_shape_id].id = current_shape_id;
                generate_variants(all_shapes[current_shape_id], shape_buffer);
                shape_buffer.clear();
            }
            current_shape_id = stoi(line.substr(0, line.find(':')));
        }
        else if (line.find("x") != string::npos && line.find(':') != string::npos) {
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

            if (req_area > (long long)W * H) {
                continue; 
            }

            sort(p_ids.begin(), p_ids.end(), [](int a, int b) {
                return all_shapes[a].area > all_shapes[b].area;
            });

            Solver solver(W, H, p_ids);
            if (solver.backtrack(0, 0)) {
                total_successes++;
            }
        }
        else {
            shape_buffer.push_back(line);
        }
    }
    
    if (!shape_buffer.empty() && current_shape_id != -1) {
         generate_variants(all_shapes[current_shape_id], shape_buffer);
    }

    cout << "Answer: " << total_successes << endl;

    return 0;
}
