//Index of the Peak in a mountain array
//Question no 852- LeetCode

#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

void Step(vector <int> ar, int x, int y)
{
    for (int i = x; i<=y; i++)
    {
        cout<< ar[i] << " "; 
    }

    cout<< endl;
    
}

int peakIndex(vector <int> ar, int size)

{
    
    int low = 0, i=0;
    int high = size-1;
    int mid;

    while(low<high)
    {
        mid = low + (high-low)/2;

        cout<<"Step "<< i+1 << " : ";
        Step(ar, low, high);

        if(ar[mid]<ar[mid+1])
        low = mid+1;
    
        else
        high = mid;

        i++;
    }

    return mid;
    
}


int main(int argc, char const *argv[])
{
    
    vector<int> arr = {0,11,26,77,78,80, 87,78,56,45,17,2};

    int ans = peakIndex(arr, arr.size());
    cout<<"Peak is on index: "<< ans << endl;

    return 0;
}
