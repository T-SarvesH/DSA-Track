//The Golden Window (P1)

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
void helper(int &n, int &k, v<int> &arr){
	
	double maxAvg = INT_MIN;
	int currSum=0, end=0;

	while(end < k){	
		currSum += arr[end];
		++end;
	}

	maxAvg=my_max<double>(maxAvg, double(currSum)/k);
	
	for(int start=0; end < n; start++, end++){
		
		currSum -= arr[start];
		currSum += arr[end];
		maxAvg = my_max<double>(maxAvg, double(currSum)/k);	
	}

	cout << maxAvg << endl;
}

int main(){
	int n, k;
	cin >> n >> k;
	
	v<int> arr(n);
	for(int i=0; i<n; ++i)
	cin >> arr[i];

	helper(n, k, arr);
	return 0;

}
