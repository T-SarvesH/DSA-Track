#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;

void pArr(int nums[], int n)
{
    for(int i=0; i<n;i++)
    {
        cout<<nums[i]<<" ";
    }

    cout<<endl;
}

void Rotate(vector<int> nums)
{
    
    int k;
    cin>>k;

    cout<<"Array after rotation: ";

    
    int ans[nums.size()];

    int n = nums.size();

    for (int i = 0; i < nums.size(); i++)
    {
        ans[(i+k)%n] = nums[i];
    }
    
    pArr(ans, nums.size());

    
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {11,71,-100,89,10,4,-3};
    Rotate(nums);


    
    return 0;
}
