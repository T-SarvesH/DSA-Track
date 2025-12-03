#include<bits/stdc++.h>

using namespace std;

vector<long long> splitter(string &inp){
	
	int p = 0;

	while(inp[p] != '-')
		++p;

	return {stoll(inp.substr(0, p)), stoll(inp.substr(p+1, inp.size()-p-1))};
}

void helper(vector<string> &input){
	
	vector<long long> store;
	long long count = 0;

	for(string &inp: input){
			
		store = splitter(inp);
		
		for(long long i=store[0]; i<=store[1]; ++i){
			
			string temp = to_string(i);
			int tempLen = temp.size(), half = tempLen / 2;

			for(int j=half; j>0; --j){
				
				if(tempLen % j)
				continue;
				
				int tempCount = 0;

				string candidate = temp.substr(0, j);

				for(int i=0; i<tempLen; i+=candidate.size()){
					
					if(temp.substr(i, candidate.size()) == candidate){
						
						++tempCount;
					}
						
					
				}

				if(tempCount == tempLen/candidate.size()){
					
					count+=i;
					break;
				}
			}
			
		}
	}

	cout << "The count is: " << count << endl;

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
