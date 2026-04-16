#include <bits/stdc++.h>
using namespace std;

void helper(int &n, vector<int> &arr){
	
	int z = 0, o = z, t = o;
	vector<int> ans;
	
	for(int &a: arr){
		a == 0? (++z): (a == 1? ++o: ++t);
	}

	for(int i=0; i<z; ++i)
		ans.push_back(0);

	for(int i=0; i<o; ++i)
		ans.push_back(1);

	for(int i=0; i<t; ++i)
		ans.push_back(2);

	for(int &a: ans)
	cout << a << " ";

	cout << endl;
}

int main(){
	
	int n;
	cin >> n;
	
	vector<int> arr(n);

	for(int i=0; i<n; ++i)
		cin >> arr[i];

	helper(n, arr);
	return 0; 
}
