#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main(){


	string word;
	cin >> word;
	
	string ans = "";

	map<char, int> mp;

	for(char ch: word){
		
		mp[ch]++;

		if(mp[ch]==9){
			
			ans.push_back(char(mp[ch] + '0'));
			ans.push_back(ch);

			mp[ch] = 0;
			
		}	
		
	}


	for(auto m: mp){
		
		ans.push_back(char(m.second + '0'));
		ans.push_back(m.first);
		
	}

	cout << ans << endl;
	
	return 0;
}
