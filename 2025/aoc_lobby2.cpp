#include<bits/stdc++.h>

using namespace std;

void helper(vector<string> &input){
	
	
	long long ans = 0;

	for(string &inp: input){

		
		int leftHighestBit = -1, rightHighestBit = -1, idx;

		for(int i=0; i < inp.size() - 1; ++i){
			
			if(leftHighestBit < inp[i] - '0'){

				leftHighestBit = inp[i] - '0';
				idx = i;
			}
		}

		for(int i=inp.size()-1; i>0; --i){

			if(idx == i)
			break;

			rightHighestBit = max(rightHighestBit, inp[i] - '0');
		}
		
		ans += (stoll(to_string(leftHighestBit) + to_string(rightHighestBit)));
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
