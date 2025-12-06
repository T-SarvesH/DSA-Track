#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> lines;
    string line;

    while (getline(cin, line)) {
        if (!line.empty())
            lines.push_back(line);
    }

    int H = lines.size();
    string ops = lines.back();
    lines.pop_back();
    H--;

    int W = lines[0].size();

    long long total = 0;
    int c = 0;

    while (c < W) {
        // skip empty columns
        bool empty = true;
        for (int r = 0; r < H; r++)
            if (lines[r][c] != ' ') empty = false;

        if (empty) {
            c++;
            continue;
        }

        // find full block width: all consecutive non-space columns
        int c2 = c;
        while (c2 < W) {
            bool colEmpty = true;
            for (int r = 0; r < H; r++)
                if (lines[r][c2] != ' ') colEmpty = false;
            if (colEmpty) break;
            c2++;
        }

        // operator is anywhere in this block
        char op = '+';
        for (int i = c; i < c2; i++) {
            if (ops[i] == '+' || ops[i] == '*')
                op = ops[i];
        }

        long long result = (op == '+') ? 0 : 1;

        // extract numbers row-wise inside block
        for (int r = 0; r < H; r++) {
            string cur = "";
            for (int i = c; i < c2; i++) {
                if (isdigit(lines[r][i])) cur += lines[r][i];
                else if (!cur.empty()) {
                    long long v = stoll(cur);
                    if (op == '+') result += v;
                    else result *= v;
                    cur = "";
                }
            }
            if (!cur.empty()) {
                long long v = stoll(cur);
                if (op == '+') result += v;
                else result *= v;
            }
        }

        total += result;
        c = c2;  // skip entire block
    }

    cout << total << endl;
    return 0;
}
