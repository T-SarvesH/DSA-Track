#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> split(string &inp){
	
	int p = 0, n = inp.size();
	while(inp[p] != ',')
		++p;
	
	return {stoi(inp.substr(0, p)), stoi(inp.substr(p+1, n-p-1))};
}
void helper(vector<string> &input){
	
	vector<vector<int>> coords;

	for(string &inp: input)	
		coords.push_back(split(inp));
	
	int n = coords.size();
	long long maxi = 0;

	for(int i=0; i<n; ++i){
		
		for(int j=i+1; j<n; ++j){
			
			int x1 = coords[i][0], x2 = coords[j][0];
			int y1 = coords[i][1], y2 = coords[j][1];

			//If in same col or row discard the pair

			if(x1 == x2 || y1 == y2)
				continue;

			int w = abs(x2 - x1) + 1, h = abs(y2 - y1) + 1;
			maxi = max(maxi, (long long)w * (long long)h);
		}
	}

	cout << "The maximum area of rectangle is: " << maxi << endl;
}

int main() {
    vector<string> input;

    string line;
    while (getline(cin, line)) {
        if (!line.empty()) 
		input.push_back(line);
    }
	
    helper(input);
    return 0;
}
