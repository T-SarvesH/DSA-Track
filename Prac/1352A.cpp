#include<bits/stdc++.h>
using namespace std;

int main(){
	
	vector<int> round;
	for(int i=0; i<=3; i++){
		
		for(int j=1; j<=9; j++){
			
			round.push_back(j * int(pow(10, i)));
		}
	}

	round.push_back(10000);
	int t;
	cin >> t;
	
	int size = round.size();
	while(t){

		int n, count=0;
		cin >> n;
		
		vector<int> ans;
		for(int k = size-1; k>=0; ){
			
			if(round[k]<=n){
				ans.push_back(round[k]);
				count++;
				n-=round[k];
			}
			--k;
		}
		
		cout << count << endl;
		for(int &a: ans)
		cout << a << " ";

		cout << endl;
		--t;
	}

	return 0;
}
