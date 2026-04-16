#include <bits/stdc++.h>
using namespace std;

int main(){
	
	long long n;
	cin >> n;

	vector<bool> sieve(1e6, true);
	for(long long i=2; i * i < 1e6; ++i){
		
		if(sieve[i]){
			
			for(long long j=i*i; j< 1e6; j += i)
				sieve[j] = false;
		}
	}

	vector<int> primes; primes.push_back(2);
	for(long long i=3; i < 1e6 ; ++i){
		
		if(sieve[i])
		primes.push_back(primes.back() + i);

	}

	auto lb = lower_bound(primes.begin(), primes.end(), 3);
	auto ub = upper_bound(primes.begin(), primes.end(), n);

	cout << ub - lb - 1 << endl;

	return 0;
}
