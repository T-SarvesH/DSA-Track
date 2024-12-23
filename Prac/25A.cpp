#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	
	int n;
	cin >> n;

	vector<int> v(n);

	for(int i=0; i<n; i++)
	cin >> v[i];
	
	unordered_map<bool, vector<int>> mp;

	for (int i = 0; i < n; ++i){

		bool val = v[i]%2==0;
		mp[val].push_back(i);

	}

	for(auto &m: mp){

		if(m.second.size()==1)
		cout << m.second[0]+1<<endl;
	}
	
	
	return 0;

}