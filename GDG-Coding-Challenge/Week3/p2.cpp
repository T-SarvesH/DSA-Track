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

v<int> prefixSum(v<int> arr){
	
	int n = arr.sz();

	for(int i=1; i<n; ++i)
	arr[i] = arr[i] + arr[i-1];
		
	return arr;
}

//Some custom functions
v<int> helper(int &n, int &k, v<int> &arr){
	
	if(!k)
	return v<int>(n, 0);
	
	v<int> prefd = prefixSum(arr);
	v<int> ans;

	if(k > 0){
		
		k%=n;
		for(int i=0; i<n; ++i)		
		ans.pb(i + k >= n? ((prefd[n-1] - prefd[i]) + prefd[(i+k)%n]) : (prefd[i+k] - prefd[i]));
		
	}
	else{
		k = abs(k) % n;
		//for(int i=0; i<n; ++i)
	}

	return ans;
	
}

int main(){

	int n, k;
	cin >> n >> k;
	
	v<int> arr(n);

	for(int i=0; i<n; ++i)
	cin >> arr[i];

	v<int> ans = helper(n, k, arr);

	[](v<int> &ans){
		for(int &a: ans)
		cout << a << " ";
		cout << endl;
	}(ans);

	return 0;
}
