// Matrix Block Sum (Code 360 PAQ)

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
ll helper(v<v<int>> &matrix, int &r1, int &c1, int &r2, int &c2){
	
	ll sum = 0;
	
	for(int i=r1; i<=r2; ++i)
		for(int j=c1; j<=c2; ++j)
			sum += matrix[i][j];
	return sum;

}

int main(){
	int n, m, r1, c1, r2, c2;
	cin >> n >> m;

	v<v<int>> matrix(n, v<int>(m));
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j)
			cin >> matrix[i][j];
	}
	cin >> r1 >> c1 >> r2 >> c2;
	cout << helper(matrix, r1, c1, r2, c2) << endl;

	return 0;
}
