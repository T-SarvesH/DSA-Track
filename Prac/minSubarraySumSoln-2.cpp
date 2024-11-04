#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;

int main(){


	int target, n;
	cin >> target >> n;

	vector<int> nums(n);

	for(int i=0; i<n; i++)
	cin >> nums[i];
	
	
	int windowStart=0;
	int sum = 0, minLen = INT_MAX;

	 for(int windowEnd=0; windowEnd < nums.size(); windowEnd++){

          //Expand Window till sum less than target
           sum += nums[windowEnd];

  //Shrink window till the point sum greater than eq to target and update minLen
		    while(sum >= target){
			minLen = min(minLen, (windowEnd - windowStart + 1));
			sum-=nums[windowStart];
			windowStart++;
		}

	}
	
	cout << (minLen==INT_MAX)? 0 : minLen << endl;

	return 0;
}
