#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, sz;
    int components;

    DSU(int n) : components(n) {
        parent.resize(n);
        sz.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            sz[i] = 1;
        }
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra == rb) return false;
        if (sz[ra] < sz[rb]) swap(ra, rb);
        parent[rb] = ra;
        sz[ra] += sz[rb];
        components--;
        return true;
    }
};

vector<int> splitCoords(const string &s) {
    vector<int> out;
    int p1 = 0;
    for (int p2 = 0; p2 <= s.size(); p2++) {
        if (p2 == s.size() || s[p2] == ',') {
            out.push_back(stoi(s.substr(p1, p2 - p1)));
            p1 = p2 + 1;
        }
    }
    return out;
}

long long squaredDist(const vector<int> &a, const vector<int> &b) {
    long long dx = a[0] - b[0];
    long long dy = a[1] - b[1];
    long long dz = a[2] - b[2];
    return dx*dx + dy*dy + dz*dz;
}

struct Edge {
    long long dist;
    int u, v;
};

int main() {
    vector<vector<int>> coords;
    string line;
    while (getline(cin, line)) {
        if (!line.empty()) coords.push_back(splitCoords(line));
    }

    int n = coords.size();
    vector<Edge> edges;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            edges.push_back({squaredDist(coords[i], coords[j]), i, j});

    sort(edges.begin(), edges.end(), [](auto &a, auto &b) {
        return a.dist < b.dist;
    });

    DSU dsu(n);
    int lastU = -1, lastV = -1;

    for (auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            lastU = e.u;
            lastV = e.v;
            if (dsu.components == 1) break;
        }
    }

    long long x1 = coords[lastU][0];
    long long x2 = coords[lastV][0];
    cout << x1 * x2 << "\n";
    return 0;
}
