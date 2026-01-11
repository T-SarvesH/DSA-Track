//P2: Alphabet scan (Method 2)
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
void helper(string &s){
	
	v<pair<char, int>> res;
	int unique=0;

	for(char c='a'; c<='z'; ++c){
		
		int uniFreq=0;
		for(char &cs: s)
		uniFreq += (cs == c);

		if(uniFreq > 0){
			unique++;
			res.pb({c, uniFreq});
		}
	}

	cout << unique << endl;
	[](v<pair<char, int>> &v){
		
		for(auto[c, freq]: v)
		cout << c << ":" << freq << " ";
	}(res);
}

int main(){
	string s;
	getline(cin, s);
	helper(s);
	return 0;
}
