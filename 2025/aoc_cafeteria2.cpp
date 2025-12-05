#include<bits/stdc++.h>
using namespace std;

vector<long long> splitter(string &inp){
	
	int p = 0;

	while(inp[p] != '-')
		++p;

	return {stoll(inp.substr(0, p)), stoll(inp.substr(p+1, inp.size()-p-1))};
}

void helper(vector<string> &input1){
	
	vector<long long> store;
	vector<vector<long long>> rangeStore;
	vector<vector<long long>> overlappedRangeStore;

	long long count = 0;

	for(string &inp: input1){
		
		store = splitter(inp);
		rangeStore.push_back(store);
	}
	
	sort(rangeStore.begin(), rangeStore.end());

	for(auto range: rangeStore){
		
		//Non-overlapping condition

		if(overlappedRangeStore.empty() || overlappedRangeStore.back()[1] < range[0])
			overlappedRangeStore.push_back(range);
		
		//Overlapping condition
		else
			overlappedRangeStore.back()[1] = max(overlappedRangeStore.back()[1], range[1]);
	}
		
	for(auto &range: overlappedRangeStore)
		count += (range[1] - range[0] + 1);

	cout << "The count is: " << count << endl;
}

int main(){

	vector<string> input1;
	string temp;

	while(true){

		cin >> temp;

		if(temp == "t")
			break;
	
		input1.push_back(temp);
	}

	helper(input1);
	return 0;
}
