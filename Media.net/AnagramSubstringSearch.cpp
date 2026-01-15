//Anagram Subs search
// Method used is slide window + freq array

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
void pr(v<int> ans){

	for(int &a: ans)
		cout << a << " ";
	
	cout << endl;
}

bool isValid(vector<int>&freq1, vector<int>&freq2){
	
	for(int i=0; i<26; ++i){
	
		if(freq1[i] != freq2[i])
			return false;
	}

	return true;
}

v<int> helper(string &str, string &ptn, int n, int m){
	
	v<int> ans;
	v<int> freq1(26, 0); v<int> freq2(26, 0);
	int start=0, end=0;
	
	for(char p: ptn)
		freq2[p - 'A']++;

	while(end < m){
		
		freq1[str[end] - 'A']++;
		++end;
	}

	if(isValid(freq1, freq2))
	ans.pb(start);

	while(end < n){
		
		//Remove start of window char and move forward the window
		freq1[str[start] - 'A']--;
		++start;

		freq1[str[end] - 'A']++;
		++end;

		if(isValid(freq1, freq2))
		ans.pb(start);
	}
	
	return ans;
}

int main(){
	string str, ptn;
	
	getline(cin, str);
	getline(cin, ptn);
	
	v<int> temp = helper(str, ptn, str.sz(), ptn.sz());
	pr(temp);
					
	return 0;
}
