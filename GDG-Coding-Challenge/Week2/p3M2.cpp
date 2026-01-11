//P3: Twin Word Check (Method 2 using sorting)

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
bool helper(string &s, string &t){

	sort(s.begin(), s.end()); sort(t.begin(), t.end());
	return s==t;
}

int main(){

	string s, t;
	getline(cin, s); getline(cin, t);
	cout << (helper(s, t)? "true": "false") << endl;
	return 0;
}
