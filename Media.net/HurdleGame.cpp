//Hurdle Game Media.net PAQ
//Mathematical soln is optimal logn, but less chances of being asked in interviews
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
int helper(int &n){
	
	int sum=0, levels=0;
	
	for(int i=1; sum + i <= n; ++i){
		++levels;
		sum+=i;
	}

	return levels;
}

int main(){

	int input;
	cin >> input;

	cout << helper(input) << endl;
	return 0;
}
