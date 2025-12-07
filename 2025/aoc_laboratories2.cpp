#include<bits/stdc++.h>
#define ll long long

using namespace std;

void setter(vector<string> &input, int &m, int &n){
	
	//Start from 2nd row
	for(int i=1; i<n; ++i){
		
		for(int j=0; j<m; ++j){
			
			//Main logic
			//If current char is ^, then follow logic
			if(input[i][j] == '^'){
				
				if(input[i-1][j] == '|'){
					
					input[i][j-1] = input[i][j+1] = '|';
				}
			}


			//If exactly upwards char is S, set curr as |
			else if(input[i-1][j] == 'S' || input[i-1][j] == '|')
				input[i][j] = '|';
		}
	}
}

// For the paths, we shall use 2D DP to accumalate sub-problem path results

long long backtrackFn(vector<string> &input, vector<vector<long long>> &dp, int i, int j, int &n){
	
	//Base case if path reaches endmost row	
	if(i == n-1)
		return 1;
	
	//Next case is if downwards char is either ^ | or .	
	if(input[i+1][j] == '|')
		return backtrackFn(input, dp, i+1, j, n);

	if(input[i+1][j] == '.')
		return 0;
	
	if(dp[i][j] != 0)
		return dp[i][j];

	//The next immediate downwards character is ^, so we split the path
	long long left = backtrackFn(input, dp, i+1, j-1, n); 
	long long right = backtrackFn(input, dp, i+1, j+1, n);

	dp[i][j] = left + right;
	return dp[i][j];
}

void helper(vector<string> &input){

	
	int m = input[0].size(), n = input.size();
	vector<vector<long long>> dp(n, vector<long long>(m, 0));

	setter(input, m, n);

	ll count = backtrackFn(input, dp, 1, m/2, n);
	cout << "The count is: " << count << endl;
}

int main(){

	vector<string> input;
	string line;

	while(getline(cin, line)){

		if(!line.empty())
			input.push_back(line);
	}

	helper(input);
	return 0;
}
