#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> lines;
    string line;

    // Read all non-empty lines including the operator row
    while (getline(cin, line)) {
        if (!line.empty())
            lines.push_back(line);
    }

    int H = lines.size();
    string ops = lines.back();   // last row is operator row
    lines.pop_back();
    H--;

    int W = lines[0].size();
    long long total = 0;

    int c = 0;
    while (c < W) {

        // Skip empty separator columns
        bool emptyCol = true;
        for (int r = 0; r < H; r++)
            if (lines[r][c] != ' ')
                emptyCol = false;

        if (emptyCol) {
            c++;
            continue;
        }

        // Find the full problem block width
        int c2 = c;
        while (c2 < W) {
            bool colEmpty = true;
            for (int r = 0; r < H; r++)
                if (lines[r][c2] != ' ')
                    colEmpty = false;
            if (colEmpty) break;
            c2++;
        }

        // Find operator in the bottom row for this block
        char op = '+';
        for (int i = c; i < c2; i++) {
            if (ops[i] == '+' || ops[i] == '*')
                op = ops[i];
        }

        // Part 2 logic:
        // Each column inside the block is ONE NUMBER
        vector<long long> numbers;

        for (int col = c; col < c2; col++) {
            string num = "";
            for (int r = 0; r < H; r++) {
                if (isdigit(lines[r][col]))
                    num += lines[r][col];
            }
            if (!num.empty()) {
                numbers.push_back(stoll(num));
            }
        }

        // Compute the block result
        long long result = (op == '+') ? 0 : 1;

        for (long long v : numbers) {
            if (op == '+') result += v;
            else result *= v;
        }

        total += result;

        // Move to next block
        c = c2;
    }

    cout << total << endl;
    return 0;
}

