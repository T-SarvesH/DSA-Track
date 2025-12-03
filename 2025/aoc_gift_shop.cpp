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

			if(to_string(i).size() % 2 == 0){
				
				string temp = to_string(i);

				cout << temp << " is element" << endl;
				int half = temp.size() / 2;
			  
				if(temp.substr(0, half) == temp.substr(half, half)){
					count += i;
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
