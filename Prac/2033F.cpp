#include<stdio.h>
#include<bits/stdc++.h>
#define mod 1000000007
	
using namespace std;

long long generate(long long n, long long k){
	
	//If k==1 basically means all n no.s divisible by k
	if(k==1)
	return n;

	//Start generating Fibonacci series
	int num1 = 0;
	int num2 = 1;

	int prev;
	long long pos = 2;

	while(true){
		
		prev = (num1)%mod + (num2)%mod;

		if(prev%k==0){

			n--;
			
			if(n==0)
			break;
		}

		num1 = (num2) % mod;
		num2 = (prev) % mod;

		pos = pos%mod + 1;
	}

	return pos;

}
int main(){

	
	int number;
	cin >> number;

	vector<long long> answer(number, 0);

	for(int i=0; i<number; i++){
		
		long long n, k;
		cin >> n >> k;

		n = n%mod;
		k = k%mod;
		
		answer[i] = generate(n, k);
	}

	for(long long n: answer)
	cout << n << endl;

}
