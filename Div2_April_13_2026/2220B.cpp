#include<bits/stdc++.h>
#define ll long long
#define li long int
#define pb push_back
#define pob pop_back
#define sz size
#define v vector
#define ump unordered_map
#define mp map
#define uset unordered_set
#define oset ordered_set

using namespace std;

// Templates 
template<typename T> T my_max(T x, T y){	
	return x >= y? x: y;
}

template<typename T> T my_min(T x, T y){
	return x >= y? y: x;
}

//Some custom functions
void helper(v<int> &tc, int &m){
	
	cout << endl;
}

int main(){
	
	int testcases, n, m, temp;
	cin >> testcases;
	v<int>tc;
	v<string> ans;

	for(int i=0; i<testcases; ++i){

		cin >> n >> m;
		for(int j=0; j<n; ++j){
			
			cin >> temp;
			tc.pb(temp);
		}

		helper(tc, m);
	}

	return 0;
}
