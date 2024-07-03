#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void binSearch(int arr[][3], int rows, int cols, int target)
{   

    int low = 0;
    int high = rows*cols -1;

    int mid;

    while (low<=high)
    {
        mid = low + (high-low)/2;

        int ans = arr[mid/cols][mid%cols];

        if(ans==target)
        {
            cout<<"Element at row "<< mid/cols << " and column " << mid%cols << endl;
            exit(0);
        }
        

        else if(ans>target)
        high = mid-1;

        else
        low = mid+1;
    }

    cout<<"Element not found :("<<endl;
    

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

    int target;
    cin>>target;

    binSearch(arr,3,3,target);
    
    return 0;
}
