//Question 88 Leetcode

#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[])
{
    
    vector<int> arr1 = {1,2,3,4,0,0,0,};
    vector<int> arr2 = {2,5,6};

    int n = arr2.size();

    int i = 0;

    while(arr1[i]!=0)
    i++;

    int j = 0;
    while (j<n)
    {
        arr1[i] = arr2[j];
        i++;
        j++;
    }

    sort(arr1.begin(), arr1.end());
    
    for(int k: arr1)
    cout<<k<<" ";

    return 0;
}
