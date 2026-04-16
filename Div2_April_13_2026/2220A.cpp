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
int helper(v<int> &tc){
	
	unordered_map<int, int> freq;
	for(int &t: tc){
		
		freq[t]++;

		if(freq[t] > 1)
		return 0;
	}

	sort(tc.rbegin(), tc.rend());
	return 1;
}

int main(){
	
	int testcases, n;
	cin >> testcases;
	v<int> tc;
	v<v<int>> ans;

	for(int i=0; i<testcases; ++i){
		
		cin >> n;
		int temp;

		for(int j=0; j<n; ++j){
			
			cin >> temp;
			tc.pb(temp);
		}

		int ans1 = helper(tc);

		if(ans1)
			ans.pb(tc);
		
		else
			ans.pb({-1});

		tc.clear();
	}

	for(auto e: ans){
		
		for(auto elm: e)
			cout << elm << " ";
		cout << endl;
	}
	return 0;
}
