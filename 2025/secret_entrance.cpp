#include<bits/stdc++.h>
using namespace std;

void helper(vector<string> &input, int &currDial){

	int countOfZeros = 0, rotFactor = -1;
	
	for(string &inp: input){
		
		rotFactor = 0;

		for(int i=1; i<inp.size(); ++i){
			
			rotFactor = rotFactor * 10 + (inp[i] - '0');
		}	
		
		rotFactor %= 100;
		char direction = inp[0];

		if(direction == 'L'){
			
			currDial -= rotFactor;
			if(currDial < 0)
				currDial += 100;
		}
		else{

			currDial += rotFactor;

			if(currDial > 99)
				currDial %= 100;
		}
		
		if(!currDial)
		++countOfZeros;
	}
	
	cout << "The actual password is: " << countOfZeros << endl; 
}

int main(){

	int currDial = 50;
	
	string temp;
	vector<string> input;

	while(true){
		
		cin >> temp;

		if(temp == "t")
		break;

		input.push_back(temp);
	}

	helper(input, currDial);
	return 0;
}
