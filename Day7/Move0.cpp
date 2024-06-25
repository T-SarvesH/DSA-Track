// Move 0 question on leetcode
// Description - https://leetcode.com/problems/move-zeroes/description/

#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

void pArr(vector<int> arr){

    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}
void move(vector<int>arr){

    
    int n = arr.size();
    int first = 0;

    for(int i=0; i<n; i++)
    {
        if(arr[i]!=0)
        {
            swap(arr[first], arr[i]);
            first++;
        }
    }

    pArr(arr);

}

int main(int argc, char const *argv[])
{
    
    vector<int> arr = {9,0,24,0,0,0,1,0};
    cout<<"Array before: ";
    pArr(arr);

    move(arr);

    pArr(arr);

    return 0;
}
