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
void helper(v<int> &input, int &n, int &rem, int idx, int &diff, int &curr){
		
	if(idx >= n){
		diff = min(diff, abs(rem));
		return;
	}

	//Include element and subtract from sum
	curr += input[idx];
	rem -= input[idx];

	helper(input, n, rem, idx+1, diff);

	//BackTrack
	
	curr -= input[idx];
	rem += input[idx];

	//Exclude
	helper(input, n, rem, idx+1, diff);
}

int main(){
	int n, rem=0, diff=INT_MAX, curr=0;
	cin >> n;

	v<int> input(n);
	for(int i=0; i<n; ++i){
		
		cin >> input[i];
		rem += input[i];
	}
	helper(input,n, rem, 0, diff, curr);
	cout << diff << endl;
	return 0;
}
