#include<bits/stdc++.h>

using namespace std;

int main(){

	int n, a,b,c;
	cin >> n >> a >> b >> c;

	vector<int> dp(n+1, INT_MIN);
	dp[0] = 0;

	for(int i=1; i<=n; i++){

		int A, B, C;
		A = B = C = INT_MIN;

		if(i-a >=0)
		A = dp[i-a] + 1;

		if(i-b >=0)
		B = dp[i-b] + 1;

		if(i-c >=0)
		C = dp[i-c] + 1;

		dp[i] = max(A, max(B, C));

	}

	cout << dp[n] << endl;

	return 0;
}