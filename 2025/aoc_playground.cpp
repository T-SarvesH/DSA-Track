#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n);
        sz.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            sz[i] = 1;
        }
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        int ra = find(a), rb = find(b);

	if(ra == rb) return;
        if (sz[ra] < sz[rb]) {
            parent[ra] = rb;
            sz[rb] += sz[ra];
        } else {
            parent[rb] = ra;
            sz[ra] += sz[rb];
        }
    }
};

vector<int> splitCoords(const string &s) {
    vector<int> out;
    int p1 = 0, n = s.size();
    for (int p2 = 0; p2 <= n; p2++) {
        if (p2 == n || s[p2] == ',') {
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
        if (!line.empty())
            coords.push_back(splitCoords(line));
    }

    int n = coords.size();
    vector<Edge> edges;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            edges.push_back({squaredDist(coords[i], coords[j]), i, j});
        }
    }

    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
        return a.dist < b.dist;
    });

    DSU dsu(n);
    int noOfEdges = 0;
    for (auto &e : edges) {
       
	 if(noOfEdges == 1000) break;
	 dsu.unite(e.u, e.v);
	 ++noOfEdges;   
    }

    vector<int> compSizes;
    for (int i = 0; i < n; i++) {
        if (dsu.find(i) == i)
            compSizes.push_back(dsu.sz[i]);
    }

    sort(compSizes.rbegin(), compSizes.rend());

    cout << compSizes[0]<< ", "<< compSizes[1] <<", "<< compSizes[2] << endl;
    long long ans = 1LL * compSizes[0] * compSizes[1] * compSizes[2];

    cout << ans << "\n";
    return 0;
}

