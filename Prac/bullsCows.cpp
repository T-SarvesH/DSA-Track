#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<string.h>

using namespace std;

int main(){

	string secret;
	string guess;

	cin >> secret >> guess;
	int n = secret.size();
	int bulls = 0, cows=0;

	unordered_map<char, int> mp;

	for(char c: secret)
	mp[c]++;

	for(int i=0; i<n; i++){

		//Case 1- Characters match
		if(secret[i]==guess[i])
		bulls++;
		
		//Case 2- Guess character at another position in secret
		else if(secret[i]!=guess[i] && mp[guess[i]] > 0){
			
			cows++;
			mp[guess[i]]--;
		}

	}

	string ans = to_string(bulls) + "A" + to_string(cows) + "B";

	cout << ans << endl;
	return 0;
}
