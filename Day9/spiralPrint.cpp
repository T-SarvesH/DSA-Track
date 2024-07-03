#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

void spiralPrint(int arr[][3],int rows, int cols)
{
    int newRow = 0;
    int newCol = 3;


    for (int i = 0; i <= newRow; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout<<arr[i][j];
        }   
    }

    newCol--;
    newRow++;

    for (int i = newRow; i < rows; i++)
    {
        for(int j = newCol; j< cols; j++)
        cout<<arr[i][j];
    }

     newCol--;
    
    // for (int i = newCol; i >=0; i--)
    // {
    //     for(int j = newCol-1; j>=0; j--)
    //     cout<<arr[i][j];
    // }
    
    
    
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
    
    spiralPrint(arr, 3, 3);

    return 0;
}
