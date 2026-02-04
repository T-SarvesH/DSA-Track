//Remove consecutive duplicates (Browserstack PAQ)

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
string helper(string &str){	
	
	string ans;
	int n = str.sz();
	for(int i=1; i<n; ++i){
		
		if(str[i] != str[i-1])
		ans.pb(str[i-1]);
	}

	ans.pb(str[n-1]);
	return ans;
}

int main(){
	string str;
	cin >> str;

	cout << helper(str) << endl;
	return 0;
}
