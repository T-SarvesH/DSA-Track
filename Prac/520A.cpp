#include<iostream>
#include<bits/stdc++.h>


using namespace std;

int main(){
	
	int n;
	cin >> n;
	
	string ans;
	cin >> ans;

	for(int i=0; i<ans.size(); i++)
	ans[i] = tolower(ans[i]);
	
	if(ans.size() < 26)
	cout << "NO" << endl;

	else{
		
		bool val = true;
		string temp = "abcdefghijklmnopqrstuvwxyz";
		unordered_map<char, int> mp;

		for(char ch: temp)
		mp[ch] = 0;

		for(char ch: ans)
		mp[ch]++;

		for(auto m: mp){
			
			if(m.second==0){
			
				cout << "NO" << endl;
				val = false;
				break;
			}
		}

		if(val)
		cout << "YES" << endl;
	}

	return 0;
}
