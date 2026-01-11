//P1: Character diversity

#include<bits/stdc++.h>
#define ll long long
#define li long int
#define pb push_back
#define pob pop_back
#define sz size
#define v vector
#define ump unordered_map
#define mp map
#define uset unordered_set
#define oset ordered_set

using namespace std;

// Templates 
template<typename T> T my_max(T x, T y){
	return x >= y? x: y;
}

template<typename T> T my_min(T x, T y){
	return x >= y? y: x;
}

//Some custom functions
void helper(string &input){
	
	v<int> freq(26, 0);
	int count = 0, n = input.sz();
	string unique;

	for(int i=0; i<n; ++i){
		
		freq[input[i] - 'a']++;

		if(freq[input[i] - 'a'] == 1){
			
			unique.pb(input[i]);
			++count;
		}
	}

	cout << count << endl;
	[](string &unique){
		
		for(char &u: unique)
			cout << u << " "; 
	}(unique);
	cout << endl;
}

int main(){
	string input;
	getline(cin, input);
	helper(input);
	return 0;
}
