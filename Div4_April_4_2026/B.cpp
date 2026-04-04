
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
void helper(vector<vector<int>> &store, vector<int> &ans){
	
	for(auto testcase: store){
	int bit = 0;
	int maxi = INT_MIN;

	for(; bit<7; ++bit){

		int sum = 0;
		for(int i=0; i<7; ++i){

			sum += (bit != i? testcase[i] * -1: testcase[i]);
		}	
		maxi = max(maxi, sum);
	}
		ans.push_back(maxi);
	}
	return;
}

int main(){
	int n;
	cin >> n;
	
	vector<int> ans;
	vector<vector<int>> store;

	for(int i=0; i<n; ++i){
		vector<int> testcase(7);
		for(int j=0; j<7; ++j)
			cin >> testcase[j];

		store.push_back(testcase);
	}
	
	helper(store, ans);
		
	for (int &a: ans)
		cout << a << endl;
	return 0;
}
