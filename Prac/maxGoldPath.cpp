#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

bool valid(int x, int y, int m, int n, vector<vector<int>>visited, vector<vector<int>>grid){

	if((x>=0 && x<m) && (y>=0 && y<n) && visited[x][y]==0 && grid[x][y]!=0)
		return true;

	return false;
}

void maxGold(int xcord, int ycord, int &curSum, int &maxSum, vector<vector<int>>&grid, vector<vector<int>>&visited,int m, int n){
	
	//Base case
	if(!valid(xcord, ycord, m, n, visited, grid)){

		//Backtrack if one path is explored completely
		maxSum = max(maxSum, curSum);
		return;
	}
	
	curSum = curSum + grid[xcord][ycord];
	visited[xcord][ycord] = 1;

	//Go to left
	maxGold(xcord, ycord-1, curSum, maxSum, grid, visited, m, n);

	//Go to right
	maxGold(xcord, ycord+1, curSum, maxSum, grid, visited, m, n);

	//Go to top
	maxGold(xcord-1, ycord, curSum, maxSum, grid, visited, m, n);

	//Go to bottom
	maxGold(xcord+1, ycord, curSum, maxSum, grid, visited, m, n);

	//Backtrack case if all paths are explored
	curSum -= grid[xcord][ycord];
	visited[xcord][ycord] = 0;

	return;
}


int main(){

	int m, n;

	cin >> m;
	cin >> n;

	vector<vector<int>> grid(m, vector<int>(n));
	vector<vector<int>> visited(m, vector<int>(n, 0));

	int maxSum = 0, curSum = 0;

	for(int i=0; i<m; i++){
		
		for(int j=0; j<n; j++){
			visited[i][j] = 0;
			cin >> grid[i][j];
			
		}
	}

	for(int i=0; i<m; i++){

		for(int j = 0; j<n; j++){
		
			if(grid[i][j]!=0)
			maxGold(i, j, curSum, maxSum, grid, visited, m, n);
		}
	}

	cout << maxSum << endl;
	return 1;
}
