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
	

	int windowStart=0, windowEnd = windowStart;
	int sum = nums[windowStart], minLen=INT_MAX, curlen=0;

	while(windowEnd < nums.size()){
		
		if(sum < target){
			windowEnd++;
			curlen++;
			if(windowEnd==nums.size())
			break;
			
			sum+=nums[windowEnd];
		}

		else{
		
			minLen = min(minLen, curlen+1);
			curlen--;
			sum-=nums[windowStart];
			windowStart++;
		}
	}

	if(minLen==INT_MAX)
	cout << "0" << endl;
	
	else
	cout << minLen << endl;

	return 0;
}
