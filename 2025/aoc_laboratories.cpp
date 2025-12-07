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

void helper(vector<string> &input){

	
	int m = input[0].size(), n = input.size();
	ll count = 0;

	setter(input, m, n);
	
	for(int i=1; i<n; ++i){
		
		for(int j=0; j<m; ++j){
			
			if(input[i][j] == '^' && input[i-1][j] == '|')
				++count;
		}
	}
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
