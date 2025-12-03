#include <bits/stdc++.h>
using namespace std;

void helper(vector<string> &input, int &currDial) {

    long long countZeros = 0;

    for (auto &inp : input) {

        int rot = 0;
        for (int i = 1; i < inp.size(); i++)
            rot = rot * 10 + (inp[i] - '0');

        char dir = inp[0];

        int full = rot / 100;
        int partial = rot % 100;

        countZeros += full;

        int start = currDial;
        int end;
        bool crosses = false;

        if (dir == 'L') {
            crosses = (start < partial);   // start→start-partial passes 0
            end = (start - partial) % 100;
            if (end < 0) end += 100;
        } else {
            crosses = (start + partial >= 100); // passes 0
            end = (start + partial) % 100;
        }

        // Count crossing only if:
        // 1. It actually crosses
        // 2. We did not start at 0
        // 3. We do NOT land on zero (landing counted separately)
        if (crosses && start != 0 && end != 0)
            countZeros++;

        // Landing on zero
        if (end == 0)
            countZeros++;

        currDial = end;
    }

    cout << "The actual password is: " << countZeros << endl;
}

int main() {
    vector<string> input;
    string s;
    int currDial = 50;

    while (cin >> s) {
        if (s == "t") break;
        input.push_back(s);
    }

    helper(input, currDial);
}

