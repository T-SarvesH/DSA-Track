/*You are given a string where characters are repeated consecutively. The task is to reduce the size of this string by representing consecutive repeated characters using the character followed by the count of its repetitions.*/

#include<bits/stdc++.h>

using namespace std;

void helper(string &s){

	
	int n = s.size(), i = 1, count = 1;
	
	char c = s[0];

	string ans = "";
	
	while(i < n){
		
		if(s[i] != s[i-1]){
			
			ans = ans + c + to_string(count);
			c = s[i];
			count = 1;
		}

		else
		++count;

		++i;
	}
	
	ans  = ans + (c + to_string(count));
	cout << ans << endl;
}

int main(){

	
	string s;
	cin >> s;

	helper(s);

	return 0;

}
