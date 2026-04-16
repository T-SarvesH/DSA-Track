#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &arr, int idx, vector<int>&dp){

	if(idx < 0)
	return 0;

	if(!idx)
	return arr[idx];

	if(dp[idx] != -1)
	return dp[idx];

	dp[idx] = arr[idx] + max(helper(arr, idx - 2, dp), helper(arr, idx - 3, dp));
	return dp[idx];
}

int main(){
	
	int n;
	cin >> n;
	
	vector<int> arr(n);

	for(int i=0; i<n; ++i)
	cin >> arr[i];
	
	vector<int> dp(arr.size() + 1, -1);

	cout << max(helper(arr, arr.size() - 1, dp), helper(arr, arr.size() - 2, dp)) << endl;

	return 0;
}
