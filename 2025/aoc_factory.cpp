#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int popcntll(ull x){ return __builtin_popcountll(x); }

int solve_machine_bits(const vector<ull>& btnMasks, ull targetMask, int n_buttons){
    int n = n_buttons;
    int m = 0;
    vector<ull> B = btnMasks;
    vector<int> pivot_row;
    vector<int> pivot_col;
    int rows = 64;
    vector<int> where(n, -1);
    int row = 0;
    for(int col=0; col<n && row<rows; ++col){
        int sel = -1;
        for(int r=row; r<n; ++r){
            if((B[r] >> col) & 1ULL){ sel = r; break; }
        }
        if(sel==-1){
            // try to find any column with bit?
        }
    }
    // We'll perform Gaussian on row-major augmented matrix instead
    int nlights = 0;
    for(auto bm: btnMasks){
        nlights = max(nlights, 64);
    }
    // Build row matrix from bit columns: but easier to build M rows based on max bit needed
    int maxbit = 0;
    for(ull bm: btnMasks) if(bm) maxbit = max(maxbit, 63 - __builtin_clzll(bm));
    maxbit = max(maxbit, (targetMask? (63 - __builtin_clzll(targetMask)) : 0));
    int R = maxbit + 1;
    if(R==0) R = 1;
    vector<vector<int>> M(R, vector<int>(n+1,0));
    for(int i=0;i<R;i++) M[i][n] = ( (targetMask>>i) & 1ULL );
    for(int j=0;j<n;j++){
        for(int i=0;i<R;i++){
            if( (btnMasks[j]>>i) & 1ULL ) M[i][j] = 1;
        }
    }
    int r = 0;
    vector<int> pivcol(R, -1);
    for(int c=0;c<n && r<R;c++){
        int sel = -1;
        for(int i=r;i<R;i++) if(M[i][c]){ sel=i; break; }
        if(sel==-1) continue;
        swap(M[r], M[sel]);
        pivcol[r] = c;
        for(int i=0;i<R;i++) if(i!=r && M[i][c]){
            for(int j=c;j<=n;j++) M[i][j] ^= M[r][j];
        }
        r++;
    }
    for(int i=r;i<R;i++) if(M[i][n]) return INT_MAX;
    vector<int> x(n,0);
    for(int i=r-1;i>=0;i--){
        int pc = pivcol[i];
        if(pc==-1) continue;
        int sum = M[i][n];
        for(int j=pc+1;j<n;j++) sum ^= (M[i][j] & x[j]);
        x[pc]=sum;
    }
    ull x0 = 0;
    for(int j=0;j<n;j++) if(x[j]) x0 |= (1ULL<<j);
    vector<int> is_pivot_col(n,0);
    for(int i=0;i<r;i++) if(pivcol[i]!=-1) is_pivot_col[pivcol[i]] = 1;
    vector<int> freecols;
    for(int j=0;j<n;j++) if(!is_pivot_col[j]) freecols.push_back(j);
    int nullity = freecols.size();
    vector<ull> nullvecs;
    for(int idx=0; idx<nullity; ++idx){
        int fc = freecols[idx];
        vector<int> v(n,0);
        v[fc]=1;
        for(int i=r-1;i>=0;i--){
            int pc = pivcol[i];
            if(pc==-1) continue;
            int sum = 0;
            for(int j=pc+1;j<n;j++) if(M[i][j]) sum ^= v[j];
            v[pc] = sum;
        }
        ull vm=0;
        for(int j=0;j<n;j++) if(v[j]) vm |= (1ULL<<j);
        nullvecs.push_back(vm);
    }
    int best = popcntll(x0);
    if(nullity<=28){
        int LIM = 1<<nullity;
        for(int mask=0; mask < LIM; ++mask){
            ull comb = 0;
            for(int b=0;b<nullity;b++) if(mask>>b &1) comb ^= nullvecs[b];
            ull cand = x0 ^ comb;
            best = min(best, popcntll(cand));
        }
        return best;
    } else {
        int TRIES = 200000;
        ull bestmask = x0;
        best = popcntll(x0);
        std::mt19937_64 rng(123456);
        for(int t=0;t<TRIES;t++){
            ull comb = 0;
            for(int b=0;b<nullity;b++) if((rng()&1)) comb ^= nullvecs[b];
            ull cand = x0 ^ comb;
            int pc = popcntll(cand);
            if(pc < best){ best = pc; bestmask = cand; }
        }
        return best;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string line;
    long long total = 0;
    vector<string> input;
    while(getline(cin,line)) if(!line.empty()) input.push_back(line);
    for(auto &machine: input){
        int p1 = machine.find('[');
        int p2 = machine.find(']');
        string pat = machine.substr(p1+1, p2-p1-1);
        ull target=0;
        for(int i=0;i<pat.size();++i) if(pat[i]=='#') target |= (1ULL<<i);
        vector<ull> btns;
        int pos = p2+1;
        while(true){
            int l = machine.find('(', pos);
            if(l==-1) break;
            int r = machine.find(')', l+1);
            string inside = machine.substr(l+1, r-l-1);
            ull m=0;
            stringstream ss(inside);
            string num;
            while(getline(ss,num,',')){
                if(num.size()){
                    int v = stoi(num);
                    m |= (1ULL<<v);
                }
            }
            btns.push_back(m);
            pos = r+1;
        }
        int res = solve_machine_bits(btns, target, btns.size());
        if(res!=INT_MAX) total += res;
    }
    cout<<total<<"\n";
    return 0;
}

