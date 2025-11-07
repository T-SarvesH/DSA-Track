#include<bits/stdc++.h>	
using namespace std;

int main(){


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long int n;
	cin >> n;
	
	while(1){
		
		cout << n << " ";
		if(n==1)
		break;

		else if(n%2==1)
		n = 3 * n + 1;

		else
		n = n/2;
	}
	
	cout << endl;
	return 0;
}
