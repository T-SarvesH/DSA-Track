#include<bits/stdc++.h>
using namespace std;

bool isAccidental(string s, int n){
	
	//Case 1
	int lower = 0,  upper = 0, det = s[0] - '\0';
	for(int i=0; i<n; i++){
	
		int ch = s[i] - '\0';
		if(ch >= 65 && ch<=90)
		++upper;

		else
		++lower;
	}

	if(upper==n || lower==1 && (det >= 97 && det <=122))
	return true;

	return false;
}

int main(){

	string s;
	cin >> s;
	
	int n = s.size();
	
	if(isAccidental(s, n)){
		
		for(int i=0; i<n; i++){
			
			int ch = s[i] - '\0';

			if(ch >= 65 && ch <= 90)
			s[i] = tolower(s[i]);

			else
			s[i] = toupper(s[i]);
		}
		cout << s << endl;
	}

	else
	cout << s << endl;

	return 0;
}
