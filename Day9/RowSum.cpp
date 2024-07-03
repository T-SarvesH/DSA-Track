#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

void rowSum(int arr[][3],int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        int rowSum = 0;

        for (int j = 0; j < cols; j++)
        {
            rowSum+=arr[i][j];
        }

        cout<<"Row "<< i+1 <<"sum is: "<< rowSum << endl;
        
    }
    
}

int main(int argc, char const *argv[])
{
    int arr[3][3];
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin>>arr[i][j];
        }
        
    }
    
    rowSum(arr, 3, 3);

    return 0;
}
