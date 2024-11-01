#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;


void letterCombos(vector<string> &ans, string combo, int index,string mapping[10], string digits){

	//Base case
	if(index >= digits.size()){
	
		ans.push_back(combo);
		return;
	}

	//Combinations of Letters
	
	int dig = digits[index] - '0';
	string map = mapping[dig];

	for(int i=0; i<map.size();i++){

		combo.push_back(map[i]);
		letterCombos(ans, combo, index+1, mapping, digits);

		//Backtrack case
		combo.pop_back();
	}
}

int main(){


	string digits;
	cin >> digits;

	string mapping [10]= {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

	vector<string> ans;
	string comb;

	letterCombos(ans, comb, 0, mapping, digits);
	
	for(string s: ans)
	cout << s <<" ";

	return 0;
}
