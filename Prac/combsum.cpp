#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void combinationSum(int curSum, int target, vector<int> &candidates, vector<int> ans, vector<vector<int>> &output, int index){
	
	//Backtrack case
	if(index == candidates.size())
	return;
	
	curSum +=  candidates[index];
	//Base Case
	if(curSum==target){
		ans.push_back(candidates[index]);
		output.push_back(ans);
		return;
	}

	//Recursive cases
	else if(curSum < target){
		ans.push_back(candidates[index]);
		combinationSum(curSum, target, candidates, ans, output, index);
	}
		
	else
	combinationSum(curSum-candidates[index], target, candidates, ans, output, index+1);
	combinationSum(curSum, target, candidates, ans, output, index+1);
	//For new set of inputs
	return;
}
int main (){

	vector<int> candidates = {2,3,6,7};
	int target = 7;
	
	vector<int> ans;
	vector<vector<int>> output;
	int idx = 0;

	for(int i=0; i<candidates.size(); i++)
	combinationSum(0, target, candidates, ans, output, i);

	for(int i=0; i<output.size(); i++){
	
		for(int j = 0; j<output[i].size(); j++)
		cout << output[i][j] << " ";

		cout << endl;
	}
	
	return 1;
}
