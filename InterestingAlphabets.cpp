//Interesting Alphabets
//Approach is simple datatying + Looping of characters
#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n; 
	cin >> n; 
	
	char ch = 'A' + (n-1);
	for(int i=0; i<n; ++i){
		
		for(char t=(ch - i); t<=ch; ++t)
		cout << t; 

		cout << endl;
	}

	return 0;
}
