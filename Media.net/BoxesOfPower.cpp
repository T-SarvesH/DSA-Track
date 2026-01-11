// Boxes of Power: MediaNet Naukri 360 PAQ

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

void helper(v<int> &gainPower, int &power){
	
	sort(gainPower.begin(), gainPower.end());

	int left=0, right=gainPower.sz()-1, score=0;

	while(left < right){
		
		//Case 1: Gainpow is less than eq to pow
		if(gainPower[left] <= power){
			
			power-=gainPower[left];
			++score;
			++left;
		}

		else{
			
			if(!score)
			break;

			--score;
			power+=gainPower[right];
			--right;
		}
			
	}

	cout << "Maximised score is: " << (gainPower[left] <= power? score+1: score) << endl;
}

int main(){
	
	int n, power;
	v <int> gainPower;

	cin >> n >> power;
	int temp;

	for(int i=0; i<n; ++i){
		
		cin >> temp;
		gainPower.pb(temp);
	}

	helper(gainPower, power);
	return 0;
}
