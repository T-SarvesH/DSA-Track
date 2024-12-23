#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

void spiralPrint(vector<vector<int>> &arr,int rows, int cols)
{
	
    int maxRow = rows, maxCol=cols, i=0, j=0;
    //Iteration 1
    for (i = 0; i <= rows-cols; i++)
    {
        for (j = 0; j < maxCol; j++)
        {
            cout<<arr[i][j] << " ";
        }   
    }

    maxCol--;
    maxRow--;

    for (i = 1; i <= maxRow; i++)
    {
        for(j = maxCol; j <= maxCol; j++)
        cout<<arr[i][j] << " ";
    }

        for (int i = maxCol-1; i<=maxRow; i++)
     {
         for(int j = maxCol-1; j>=0; j++)
         cout<<arr[i][j];
    }
	
    maxRow--;

    for(int i=maxRow+1; i > maxCol-1; i--){
	
	    for(int j=maxCol; j>=0; j--)	   
             cout << arr[i][j];
    }

    maxCol--;

    for(; i<maxCol; i++){
	
	    for(j=maxRow; j<=maxCol; j++)
            cout << arr[i][j];
    }
    
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> arr(3, vector<int>(3));
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin>>arr[i][j];
        }
        
    }
    
    int rows = arr.size();
    int cols = arr[0].size();
    spiralPrint(arr, rows, cols);

    return 0;
}
