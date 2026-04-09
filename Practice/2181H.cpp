#include<bits/stdc++.h>
#define ll long long
#define li long int
#define pb push_back
#define pob pop_back
#define sz size
#define v vector
#define ump unordered_map
#define mp map
#define uset unordered_set
#define oset ordered_set

using namespace std;

// Templates 
template<typename T> T my_max(T x, T y){
	
	return x >= y? x: y;
}

template<typename T> T my_min(T x, T y){
	
	return x >= y? y: x;
}

//Some custom functions
void helper(ll &w, ll &h, ll &d, ll &n){
	

	//Find factors of w
	vector<ll> wFactors;
	for(ll i=1; i*i<=w; ++i){
		
		if(w % i)
		continue;

		else{
			wFactors.push_back(i);
			if(w / i != i)
				wFactors.push_back(w/i);
		}
	}

	//Find factors of b	
	vector<ll> hFactors;
	for(ll i=1; i*i<=h; ++i){
		
		if(h % i)
		continue;

		else{
			hFactors.push_back(i);
			if(h / i != i)
				hFactors.push_back(h/i);
		}
	}
	
	for(auto wf: wFactors){
		
		for(auto hf: hFactors){
			
			int curr = wf * hf;
			if(!(n % curr)){
				
				ll df = n / curr;
				if(!(d % df)){
					cout << wf - 1 << " " << hf - 1 << " " << df - 1 << endl;
					return;
				}
			}

		}
	}
	cout << -1 << endl;	
}

int main(){
	ll w, h, d, n;
	cin >> w >> h >> d >> n;
	
	helper(w, h, d, n);
	return 0;
}
