// In-place character flip 

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
	
	int n = line.sz();
	for(int left=0, right=n-1; left <= right; left++, right--)
		swap(line[left], line[right]);

	cout << "The reversed string is: " << line << endl;
}

int main(){
	string line;
	getline(cin, line);

	if(!line.empty())
	helper(line);

	return 0;
}
