/* Daily Question: 1st November 2024 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>

using namespace std;

string fancyString(string s, string ans){

	int n = s.size();

	if(n<3)
	return s;

	for(int i=0; i<n; i++){
		
		if(i<2)
		ans.push_back(s[i]);

		else if(s[i]==s[i-1] && s[i]==s[i-2])
		continue;

		else
		ans.push_back(s[i]);
	}
	return ans;
}
int main(){

	string s;
	cin >> s;

	string ans;

	ans = fancyString(s, ans);
	
	cout << ans << endl;
	return 0;
}
