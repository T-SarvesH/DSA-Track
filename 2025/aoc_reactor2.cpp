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

ll dfs(unordered_map<string, vector<string>> &ump, unordered_map<string, int> &stringIds, vector<vector<vector<ll>>> &dp, string curr, bool isdac, bool isfft){
	
	//Base case
	if(curr == "out")
		return isdac && isfft? 1: 0;
	
	if(dp[stringIds[curr]][isdac][isfft] != -1)
		return dp[stringIds[curr]][isdac][isfft];

	if(curr == "dac")
		isdac = true;

	if(curr == "fft")
		isfft = true;
	
	ll ways = 0;
	//Else for curr, check all of its neighbours for a possible path	
	for(string &neighbour: ump[curr])
		ways += dfs(ump, stringIds, dp, neighbour, isdac, isfft);

	dp[stringIds[curr]][isdac][isfft] = ways;
	return dp[stringIds[curr]][isdac][isfft];
}
void helper(vector<string> &input){

	unordered_map<string, vector<string>> ump;
	unordered_map<string, int> stringIds;
	pair<string, vector<string>> temp;
	int i=0;

	for(string &inp: input){
		
		temp = splitter(inp);
		ump[temp.first] = temp.second;
		stringIds[temp.first] = i;
		++i;
	}
	
	vector<vector<vector<ll>>> dp(stringIds.size(), vector<vector<ll>>(2, vector<ll>(2, -1)));
	cout << "The number of ways is: " << dfs(ump, stringIds, dp, "svr", false, false) << endl;

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
