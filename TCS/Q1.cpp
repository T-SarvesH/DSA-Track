#include <bits/stdc++.h>
using namespace std;

void helper(int &n, vector<int>&choc){
	
	int count = 0;
	vector<int> ans;

	for(int &c: choc){
		
		if(!c)
		++count;

		else
		ans.push_back(c);
	}
	
	for(int i=0; i<count; ++i)
		ans.push_back(0);

	for(int &a: ans)
	cout << a << " ";

	cout << endl;
}

int main(){

	int n;
	cin >> n;

	vector<int> choc(n);
	
	for(int i=0; i<n; ++i)
		cin >> choc[i];

	helper(n, choc);
	return 0;
}

