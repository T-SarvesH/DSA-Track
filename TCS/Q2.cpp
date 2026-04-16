#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n, sum = 0;
	cin >> n;

	vector<int> bits;
	while(n){
		
		//We push the flipped bits in a reverse order and perform a right shift
		bits.push_back((n & 1) == 0);
		n = n >> 1;
	}
	
	for(int i=0; i<bits.size(); ++i)	
		sum += (pow(2, i) * bits[i]);
	
	
	cout << sum << endl;
	return 0;
}	
