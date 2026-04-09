#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void helper(vector<pair<ll, ll>> &testcases) {
    for (auto &p : testcases) {
        ll a = p.first;
        ll b = p.second;
        ll prod = a * b;
        ll maxi = -1;

        if ((prod + 1) % 2 == 0) {
            maxi = max(maxi, prod + 1);
        }

        if (b % 2 == 0) {
            ll val2 = (prod / 2) + 2;
            if (val2 % 2 == 0) {
                maxi = max(maxi, val2);
            }
        }

        if ((a + b) % 2 == 0) {
            maxi = max(maxi, a + b);
        }

        cout << maxi << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    vector<pair<ll, ll>> testcases(t);
    for (int i = 0; i < t; ++i) {
        cin >> testcases[i].first >> testcases[i].second;
    }

    helper(testcases);

    return 0;
}
