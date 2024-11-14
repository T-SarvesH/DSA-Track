#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;


void generate(vector<string> &ans, string &genr, int n){

	if(n==0){
		
		ans.push_back(genr);
		return;
	}


	if(genr.empty() || genr.back()=='1'){
		
		generate(ans, genr + '0', n-1);

		//BackTrack for appending 1
		genr.pop_back();
		generate(ans, genr + '1', n-1);
	}

	else	
	generate(ans, genr+'1', n-1);
	
	//BackTrack Case
	genr.pop_back();

}
int main(){

	int n;
	cin >> n;
	
	string genr = "";
	vector<string> ans;
	
	generate(ans, genr, n);

	for(auto s: ans)
	cout << s << endl;

	return 0;
}
