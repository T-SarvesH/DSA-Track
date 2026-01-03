// String sanitizer

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
#define mod 1000000007

using namespace std;

// Templates 
template<typename T> T my_max(T x, T y){
	
	return x >= y? x: y;
}

template<typename T> T my_min(T x, T y){
	
	return x >= y? y: x;
}


void helper(string &line){
	
	string ans;

	for(char l: line){
		
		if(l>='a' && l<='z')
		ans.push_back(l);
	}	
	
	cout << "The cleaned string is: " << ans << endl;
}

int main(){
	string s;
	getline(cin, s);

	if(!s.empty())
	helper(s);

	return 0;
}
