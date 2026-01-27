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
int helper(string &s, int &n){
	
	if(n < 1)
	return 0;

	int maxLen=1, start=0, end=0;

	//Assuming the string only contains lowercase letters	
	v<int> freq(26, 0);

	while (end < n) {
		
		freq[s[end] - 'a']++;
		//The current char which enters the window will always be unique or repeated
		//So we shrink the window until that char becomes unique in the window
		while (freq[s[end] - 'a'] > 1) {
			freq[s[start] - 'a']--;
			++start;
		}
		
		maxLen = my_max<int>(maxLen, end - start + 1);
		++end;
	}

	return maxLen;
}

int main(){
	string s;
	cin >> s;
	
	int n = s.sz();
	cout << helper(s, n) << endl;

	return 0;
}
