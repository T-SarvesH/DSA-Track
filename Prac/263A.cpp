#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;

int main(){


	vector<vector<int>>matrix(5, vector<int>(5));
	int xc, yc;

	for(int i=0; i<5; i++){


		for(int j=0; j<5; j++){

			cin >> matrix[i][j];

			if(matrix[i][j]==1){
				
				xc = i;
				yc = j;

			}
		}
	}
	

	int ans = abs(2-xc) + abs(2-yc);
	cout << ans << endl;

	return 0;
}
