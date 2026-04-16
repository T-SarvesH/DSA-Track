#include <bits/stdc++.h>
using namespace std;

void helper(vector<priority_queue<int, vector<int>, greater<int>>> &testcaseVector, vector<int> &ans){
	
	for(auto &tcv: testcaseVector){
	
		int sum = 0, f, b;
		
		while(1){
			
			f = tcv.top();
			tcv.pop();
			b = tcv.top();
			tcv.pop();

			sum += (f + b);

			if(tcv.empty())
				break;

			tcv.push(f + b);
		}

		ans.push_back(sum);
	}
	
	for(int &a: ans)
		cout << a << " ";

	cout << endl;

}

int main(){

	int testcases, n, t;
	cin >> testcases;
	
	vector<int> ans;
	vector<priority_queue<int, vector<int>, greater<int>>> testcaseVector(testcases);

	for(int i=0; i<testcases; ++i){
		
		cin >> n;

		for(int j=0; j<n; ++j){
			cin >> t;
			testcaseVector[i].push(t);
		}
	}

	helper(testcaseVector, ans);

	return 0;
}
