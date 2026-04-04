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
	
	for(int &t: testcases)
		cout << t + (t >= 67? 0: 1) << endl;

	return;
}

int main(){
	
	// Number of test cases
	int n;
	cin >> n;

	vector<int> testcases(n);
	for(int i=0; i<n; ++i)
	cin >> testcases[i];

	helper(testcases);

	return 0;
}
