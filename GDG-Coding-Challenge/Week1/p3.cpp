// Mirror Check String

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

void helper(string &line){
	
	string ans;
	bool isPalindrome = true;

	for(char l: line){
		
		if((l>='a' && l<='z') || (l>='0' && l<='9') || (l>='A' && l<='Z'))
		ans.push_back(tolower(l));
	}	
		
	int n = ans.sz();
	for(int left=0, right=n-1; left <= right; left++, right--){
		
		if(ans[left] != ans[right]){
			isPalindrome = false;
			break;
		}
	}
	cout << (isPalindrome? "true": "false") << endl;
}

int main(){
	string s;
	getline(cin, s);

	if(!s.empty())
	helper(s);

	return 0;
}
