#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

void Waveprint(int arr[][3],int rows, int cols)
{
    for (int i = 0; i < cols; i++)
    {
        if(i%2==0)
        {
            for (int j = 0; j < rows; j++)
            {
                cout<<arr[j][i]<< " ";
            }
            
        }

        else{

            for (int j = rows-1; j >= 0; j--)
            {
                cout<<arr[j][i]<< " ";
            }
            
        }
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
    
    Waveprint(arr, 3, 3);

    return 0;
}
