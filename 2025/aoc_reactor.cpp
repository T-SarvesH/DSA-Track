#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

pair<string, vector<string>> splitter(string &input){
	
	vector<string> op;
	int p = 0;
	while(input[p]!=':')
		++p;

	string temp;
	stringstream ss(input.substr(p+1));

	while(ss >> temp)
		op.pb(temp);

	return {input.substr(0, p),op};

}

void dfs(unordered_map<string, vector<string>> &ump, ll &ways, string curr){
	
	//Base case
	if(curr == "out"){
		
		++ways;
		return;
	}

	//Else for curr, check all of its neighbours for a possible path	
	for(string &neighbour: ump[curr])
		dfs(ump, ways, neighbour);
}
void helper(vector<string> &input){

	unordered_map<string, vector<string>> ump;
	pair<string, vector<string>> temp;

	for(string &inp: input){
		
		temp = splitter(inp);
		ump[temp.first] = temp.second;
	}

	ll ways = 0;
	dfs(ump, ways, "you");

	cout << "The number of ways is: " << ways << endl;

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
