#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int maxSubarray(vector<int> &nums){

	int curSum =0, maxSum= INT_MIN;

	for(int n: nums){
	
		curSum = max(curSum+n, n);

		maxSum = max(curSum, maxSum);
	}	
	
	return maxSum;
}

int main(){

	int n;
	cin>>n;
	
	vector<int> nums(n);

	for(int i=0; i<n; i++)
	cin >> nums[i];
	
	int fin = maxSubarray(nums);

	cout << fin << endl;
	return 1;
}
