#include<bits/stdc++.h>
using namespace std;


int main(){

	string s;
	cin >> s;

	s[0] = toupper(s[0]);
	int n = s.size();

	for(int i=1; i<n; i++)
	s[i] = tolower(s[i]);

	cout << s << endl;
	return 0;
}
