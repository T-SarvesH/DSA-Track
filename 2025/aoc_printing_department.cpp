/* Day 4: Part 2 */

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> directions = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}, {-1, -1}, {1, -1}, {1, 1}, {-1, 1}};

bool check(vector<string> &input, int &x, int &y, int &m, int &n){

	int count = 0;
	
	for(auto dir: directions){
		
		int newX = x + dir[0];
		int newY = y + dir[1];
		

		if(newX >=0 && newX < m && newY >=0 && newY < n && input[newX][newY] == '@')
			++count;
	}

	return count < 4;
	
}

void helper(vector<string> &input){
	
	
	long long ans = 0;
	int m = input.size(), n = input[0].size();

	for(int i=0; i<m; ++i){

		for(int j=0; j<n; ++j){
			
			if(input[i][j] == '@' && check(input, i, j, m, n))
				++ans;
		}
	}
	
	cout << "The answer is: " << ans << endl;
}

int main(){

	vector<string> input;
	string temp;

	while(true){

		cin >> temp;

		if(temp == "t")
			break;
	
		input.push_back(temp);
	}

	helper(input);
	
	return 0;
}
