// Reversing an array

#include<stdio.h>
#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

void pArr(vector<int> arr)
{

    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(int argc, char const *argv[])
{
    vector<int> v  = {89,781,789,81,98,565};

    //Method 1
    for (int i = 0, j = v.size()-1; i <= j; i++, j--)
    {
        swap(v[i], v[j]);
        cout<<"After swap"<< i+1 << ": ";
        pArr(v);
    }

    //Method 2
    reverse(v.begin(), v.end());
    pArr(v);
    
    return 0;
}
