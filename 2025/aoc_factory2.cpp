#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

using Real = long double;

struct Machine {
    vector<vector<int>> buttons;
    vector<long long> targets;
};

long long min_presses_machine;
bool solution_found_for_machine;

Machine parse_line(const string& line) {
    Machine m;
    size_t brace_pos = line.find('{');
    string target_str = line.substr(brace_pos + 1, line.find('}') - brace_pos - 1);
    stringstream ss_t(target_str);
    string segment;
    while (getline(ss_t, segment, ',')) {
        m.targets.push_back(stoll(segment));
    }

    size_t i = line.find('(');
    while (i != string::npos && i < brace_pos) {
        size_t end = line.find(')', i);
        string btn_content = line.substr(i + 1, end - i - 1);
        vector<int> effects;
        stringstream ss_b(btn_content);
        while (getline(ss_b, segment, ',')) {
            effects.push_back(stoi(segment));
        }
        m.buttons.push_back(effects);
        i = line.find('(', end);
    }
    return m;
}

bool is_integer(Real val) {
    return abs(val - round(val)) < 1e-5;
}

void search_free_vars(int free_idx, 
                      const vector<int>& free_cols, 
                      const vector<int>& pivot_row_of_col,
                      const vector<vector<Real>>& matrix,
                      const vector<Real>& rhs,
                      vector<long long>& solution,
                      int num_vars,
                      int num_eq) {
    
    if (free_idx == free_cols.size()) {
        long long current_sum = 0;
        bool valid = true;
        
        for (int j = 0; j < num_vars; ++j) {
            int r = pivot_row_of_col[j];
            if (r != -1) {
                Real val = rhs[r];
                for (int f_col : free_cols) {
                    val -= matrix[r][f_col] * (Real)solution[f_col];
                }
                
                if (val < -1e-5 || !is_integer(val)) {
                    valid = false;
                    break;
                }
                solution[j] = (long long)round(val);
            }
            current_sum += solution[j];
        }

        if (valid) {
            if (!solution_found_for_machine || current_sum < min_presses_machine) {
                min_presses_machine = current_sum;
                solution_found_for_machine = true;
            }
        }
        return;
    }

    int f_col = free_cols[free_idx];
    for (int val = 0; val <= 20000; ++val) { 
        solution[f_col] = val;
        search_free_vars(free_idx + 1, free_cols, pivot_row_of_col, matrix, rhs, solution, num_vars, num_eq);
    }
}

void process_machine(const Machine& m, long long& total_presses) {
    int num_eq = m.targets.size();
    int num_vars = m.buttons.size();

    vector<vector<Real>> A(num_eq, vector<Real>(num_vars, 0.0));
    vector<Real> b(num_eq);

    for (int i = 0; i < num_eq; ++i) b[i] = (Real)m.targets[i];
    for (int j = 0; j < num_vars; ++j) {
        for (int counter_idx : m.buttons[j]) {
            if (counter_idx < num_eq) A[counter_idx][j] = 1.0;
        }
    }

    int pivot_row = 0;
    vector<int> pivot_row_of_col(num_vars, -1); 

    for (int col = 0; col < num_vars && pivot_row < num_eq; ++col) {
        int sel = -1;
        for (int row = pivot_row; row < num_eq; ++row) {
            if (abs(A[row][col]) > 1e-9) { sel = row; break; }
        }
        if (sel == -1) continue;

        swap(A[pivot_row], A[sel]);
        swap(b[pivot_row], b[sel]);
        
        Real div = A[pivot_row][col];
        for (int j = col; j < num_vars; ++j) A[pivot_row][j] /= div;
        b[pivot_row] /= div;

        for (int row = 0; row < num_eq; ++row) {
            if (row != pivot_row && abs(A[row][col]) > 1e-9) {
                Real factor = A[row][col];
                for (int j = col; j < num_vars; ++j) A[row][j] -= factor * A[pivot_row][j];
                b[row] -= factor * b[pivot_row];
            }
        }
        pivot_row_of_col[col] = pivot_row;
        pivot_row++;
    }

    for (int row = pivot_row; row < num_eq; ++row) {
        if (abs(b[row]) > 1e-5) return;
    }

    vector<int> free_cols;
    for(int j=0; j<num_vars; ++j) {
        if (pivot_row_of_col[j] == -1) free_cols.push_back(j);
    }

    min_presses_machine = -1;
    solution_found_for_machine = false;
    vector<long long> solution(num_vars, 0);
    
    search_free_vars(0, free_cols, pivot_row_of_col, A, b, solution, num_vars, num_eq);

    if (solution_found_for_machine) {
        total_presses += min_presses_machine;
    }
}

int main() {
    long long total_presses = 0;
    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue;
        Machine m = parse_line(line);
        process_machine(m, total_presses);
    }
    cout << "Total Presses: " << total_presses << endl;
    return 0;
}
