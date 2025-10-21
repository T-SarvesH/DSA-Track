/* You’re given an array of integers, print the number of times each integer has
occurred in the array.

Example
Input :
10
1 2 3 3 4 1 4 5 1 2
Output :
1 occurs 3 times
2 occurs 2 times
3 occurs 2 times
4 occurs 2 times
5 occurs 1 times

*/

#include<bits/stdc++.h>

using namespace std;

int main(){

	
	int n;
	cin >> n;

	vector<int> v;
	int temp = -1;

	for(int i=0; i<n; ++i){
		
	    cin >> temp;
	    v.push_back(temp);
	}

	map<int, int> m;

	for(auto elm: v)
		m[elm]++;

	for(auto pair: m){
	
		cout << pair.first <<" occurs " << pair.second <<" times " << endl;
	}

	return 0;


}
