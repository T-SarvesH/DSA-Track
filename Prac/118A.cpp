#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

bool isVowel(char ch){


	string verify = "aeiouyAEIOUY";

	for(char chr: verify){
		
		if(ch==chr)
		return true;
	}

	return false;
}

int main(){

	
	string inp;
	cin >> inp;

	string ans = "";

	for(auto ch: inp){
	
		if(isVowel(ch))
		continue;

		else{
			
			ans.push_back('.');
			char c = tolower(ch);
			ans.push_back(c);
		}
	}

	cout << ans << endl;

	return 0;
}
