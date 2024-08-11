#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> nums;
    pair<int,int> p;

    int n;

    cin>>n;

    for (int i = 0; i < n; i++)
    {
        int t1;
        cin>>t1;
        nums.push_back(t1);
    }

    sort(nums.begin(), nums.end());
    cout << "Sorted array is: " << endl;

    for (int i = 0; i < n; i++)
    cout<<nums[i]<<" ";
    
    cout<< endl;
    int trav = 0;

    while(trav+1<n)
    {
        if((nums[trav] ^ nums[trav+1])!=0)
        {
            p.first = nums[trav];
            p.second = nums[trav+1];
            break;
        }

        trav = trav+2;
    }
    cout<< "The elements are: " << p.first << " " << p.second << endl;
    return 0;
}
