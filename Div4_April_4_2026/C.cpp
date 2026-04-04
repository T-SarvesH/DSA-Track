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
void helper(vector<int> &testcases){
	
	vector<vector<int>> store;

	for(int &t: testcases){
		
		vector<int> ans;
		int p = t;
		
		for(int count=0, i = 3*t - 1; count < t; ++count, i-=2, p--){
			
			ans.push_back(i); ans.push_back(i+1); ans.push_back(p);	
		
		}

		store.push_back(ans);	
	}
	
	for(auto &s: store){
		for(auto &elm: s){
			cout << elm << " ";
		}
		cout << endl;
	}
	return;
}

int main(){
	int n;
	cin >> n;

	vector<int> testcases(n);
	for(int i=0; i<n; ++i)
		cin >> testcases[i];

	helper(testcases);

	return 0;
}
