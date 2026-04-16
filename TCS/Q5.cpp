#include <bits/stdc++.h>
using namespace std;

void helper(vector<int> &samples, vector<vector<int>> &ranges){

	vector<vector<int>> ans;
	for(auto &r: ranges){
		
		// We find the lower and upper bound and use that to calculate the number of samples in the range

		auto lb = lower_bound(samples.begin(), samples.end(), r[0]);
		auto ub = upper_bound(samples.begin(), samples.end(), r[1]);

		cout << ub - lb << endl;
	}
}

int main(){
	
	int s, n;
	cin >> s >> n;
	
	vector<int> samples(s);
	vector<vector<int>> ranges(n, vector<int>(2));

	for(int i=0; i<s; ++i)
	cin >> samples[i];
	
	for(int i=0; i<n; ++i)	
	cin >> ranges[i][0] >> ranges[i][1];
	
	//Sorting the samples for upper and lower bound
	sort(samples.begin(), samples.end());
	helper(samples, ranges);

	return 0;
}
