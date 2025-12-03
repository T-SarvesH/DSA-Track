#include<bits/stdc++.h>
using namespace std;

//Construct lex largest string of len 12 from available chars
string lexGreater(string &inp){
	
	string ans = "";
	vector<char> s;
	
	int toDrop = inp.size() - 12;

	for(char &i: inp){
		
		while(!s.empty() && s.back() < i && toDrop > 0){
			
			s.pop_back(); --toDrop;
		}

		s.push_back(i);
	}

	while(s.size() > 12)
		s.pop_back();

	return string(s.begin(), s.begin() + 12);
}

void helper(vector<string> &input){
	
	
	long long ans = 0;

	for(string &inp: input){
		
		string lexLargest = lexGreater(inp);	
		ans += stoll(lexLargest);
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
