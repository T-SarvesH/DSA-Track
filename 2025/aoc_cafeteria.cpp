#include<bits/stdc++.h>

using namespace std;

vector<long long> splitter(string &inp){
	

	int p = 0;

	while(inp[p] != '-')
		++p;

	return {stoll(inp.substr(0, p)), stoll(inp.substr(p+1, inp.size()-p-1))};
}

void helper(vector<string> &input1, vector<long long> &input2){
	
	vector<long long> store;
	vector<vector<long long>> rangeVectors;

	long long count = 0;
	

	for(string &inp: input1){
	
		store = splitter(inp);
		rangeVectors.push_back(store);
	}


	//Traverse all values and check which are not set
	
	for(long long &inp: input2){
		
		bool isPresent = false;
		for(auto range: rangeVectors){
			
			if(inp >= range[0] && inp <= range[1]){

				isPresent = true;
				break;
			}
		}

		if(isPresent)
			++count;
	}
	
	cout << "The count is: " << count << endl;

}

int main(){

	vector<string> input1;
	vector<long long> input2;

	string temp;
	long long temp1;

	while(true){

		cin >> temp;

		if(temp == "t")
			break;
	
		input1.push_back(temp);
	}

	while(true){

		cin >> temp1;

		if(temp1 == 1e16)
			break;

		input2.push_back(temp1);
	}

	helper(input1, input2);
	return 0;
}
