#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

bool inside(const vector<pair<ll,ll>>& P, ld x, ld y) {
    bool in = false;
    int n = P.size();
    for (int i = 0, j = n - 1; i < n; j = i++) {
        auto [xi, yi] = P[i];
        auto [xj, yj] = P[j];

        bool hit = ((yi > y) != (yj > y)) &&
                   (x < (ld)(xj - xi) * (y - yi) / (ld)(yj - yi) + xi);
        if (hit) in = !in;
    }
    return in;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<ll,ll>> reds;
    string s;

    while (getline(cin,s)) {
        if (s.empty()) continue;
        auto p = s.find(',');
        ll x = stoll(s.substr(0,p));
        ll y = stoll(s.substr(p+1));
        reds.emplace_back(x,y);
    }

    int n = reds.size();

    // Build full boundary path (red -> green -> red)
    vector<pair<ll,ll>> poly;
    for (int i = 0; i < n; i++) {
        auto [x1,y1] = reds[i];
        auto [x2,y2] = reds[(i+1)%n];

        if (x1 == x2) {
            if (y1 <= y2) for (ll y=y1; y<=y2; y++) poly.emplace_back(x1,y);
            else          for (ll y=y1; y>=y2; y--) poly.emplace_back(x1,y);
        } else {
            if (x1 <= x2) for (ll x=x1; x<=x2; x++) poly.emplace_back(x,y1);
            else          for (ll x=x1; x>=x2; x--) poly.emplace_back(x,y1);
        }
    }

    // Remove duplicate consecutive vertices
    poly.erase(unique(poly.begin(), poly.end()), poly.end());

    ll best = 0;

    for (int i = 0; i < n; i++) {
        auto [x1,y1] = reds[i];
        for (int j = i+1; j < n; j++) {
            auto [x2,y2] = reds[j];
            if (x1==x2 || y1==y2) continue;

            ld lx = min(x1,x2) + 0.5L;
            ld rx = max(x1,x2) + 0.5L;
            ld ly = min(y1,y2) + 0.5L;
            ld ry = max(y1,y2) + 0.5L;

            if (inside(poly,lx,ly) &&
                inside(poly,lx,ry) &&
                inside(poly,rx,ly) &&
                inside(poly,rx,ry))
            {
                ll area = llabs(x1-x2) * llabs(y1-y2);
                best = max(best, area);
            }
        }
    }

    cout << best << "\n";
    return 0;
}

