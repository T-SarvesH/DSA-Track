#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    long long x;
    long long y;
};

// Helper: Ray Casting to check if a point is generally inside
// We use a small epsilon to avoid issues when the midpoint lands exactly on a line
bool is_inside(double test_x, double test_y, const vector<Point>& polygon) {
    bool inside = false;
    size_t j = polygon.size() - 1;
    for (size_t i = 0; i < polygon.size(); ++i) {
        double xi = (double)polygon[i].x;
        double yi = (double)polygon[i].y;
        double xj = (double)polygon[j].x;
        double yj = (double)polygon[j].y;

        bool intersect = ((yi > test_y) != (yj > test_y)) &&
                         (test_x < (xj - xi) * (test_y - yi) / (yj - yi) + xi);
        if (intersect) inside = !inside;
        j = i;
    }
    return inside;
}

// Helper: Check if a polygon edge slices through the rectangle
bool edge_intersects_rect(Point p1, Point p2, long long min_x, long long max_x, long long min_y, long long max_y) {
    // 1. Check Vertical Edge
    if (p1.x == p2.x) {
        // Edge is at X. If X is strictly inside the rectangle's width...
        if (p1.x > min_x && p1.x < max_x) {
            long long y_start = min(p1.y, p2.y);
            long long y_end = max(p1.y, p2.y);
            // ...and the Edge's Y-range overlaps with the rectangle's Y-range
            if (max(y_start, min_y) < min(y_end, max_y)) {
                return true;
            }
        }
    }
    // 2. Check Horizontal Edge
    else if (p1.y == p2.y) {
        // Edge is at Y. If Y is strictly inside the rectangle's height...
        if (p1.y > min_y && p1.y < max_y) {
            long long x_start = min(p1.x, p2.x);
            long long x_end = max(p1.x, p2.x);
            // ...and the Edge's X-range overlaps with the rectangle's X-range
            if (max(x_start, min_x) < min(x_end, max_x)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    // 1. Parse Input
    vector<Point> points;
    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue;
        size_t commaPos = line.find(',');
        if (commaPos != string::npos) {
            points.push_back({stoll(line.substr(0, commaPos)), stoll(line.substr(commaPos + 1))});
        }
    }

    size_t n = points.size();
    long long max_area = 0;

    // 2. Check all pairs
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = i + 1; j < n; ++j) {
            Point p1 = points[i];
            Point p2 = points[j];

            long long min_x = min(p1.x, p2.x);
            long long max_x = max(p1.x, p2.x);
            long long min_y = min(p1.y, p2.y);
            long long max_y = max(p1.y, p2.y);

            // Inclusive Area
            long long width = (max_x - min_x) + 1;
            long long height = (max_y - min_y) + 1;
            long long area = width * height;

            if (area <= max_area) continue;

            // CHECK A: Do any polygon edges slice through this rectangle?
            // This catches the case where the rectangle bridges a gap or notch.
            bool edge_violation = false;
            size_t prev = n - 1;
            for (size_t k = 0; k < n; ++k) {
                if (edge_intersects_rect(points[prev], points[k], min_x, max_x, min_y, max_y)) {
                    edge_violation = true;
                    break;
                }
                prev = k;
            }
            if (edge_violation) continue;

            // CHECK B: Is the center inside?
            // This ensures we aren't in a hole or completely outside.
            // We use a small epsilon offset to avoid "on-the-line" ray casting errors.
            double mid_x = (min_x + max_x) / 2.0;
            double mid_y = (min_y + max_y) / 2.0;
            
            if (is_inside(mid_x, mid_y + 0.0001, points)) {
                max_area = area;
            }
        }
    }

    cout << "Largest Valid Area: " << max_area << endl;
    return 0;
}
