#include<stdio.h>
#include<bits/stdc++.h>
#include<iostream>
#include<math.h>

using namespace std;

int firstMissing(vector<int> &nums)
{

    int n = pow(10, 5);
    vector<long int> freq (n+1, 0);
    
    for (int i = 0; i < nums.size(); i++)
    {
        if(nums[i]<=0 || nums[i] > n)
        continue;

        else{

            freq[nums[i]]++;
        }
    }

    long int i = 1;
    for (; i < freq.size(); i++)
    {
        if(freq[i]==0)
        break;
    }
    return i;
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    vector<int> nums(n);

    for(int i=0; i<n; i++)
    {
        int temp;
        cin>>temp;
        nums.push_back(temp);
    }

    int firstMiss = firstMissing(nums);

    cout<<"First missing Positive is: " << firstMiss << endl;
    return 0;
}
