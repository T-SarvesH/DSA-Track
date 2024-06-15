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


int Pivot(vector<int>ans)
{
    int low = 0;
    int high = ans.size()-1;
    int mid;

    while (low<high)
    {
        mid = low + (high-low)/2;

        if(ans[mid]>=ans[0])
        low = mid+1;

        else
        high = mid;
    }
    return low;
    
}

int binSearch(vector<int> ar, int low, int high, int target)
{
    int mid;

    while (low<=high)
    {
        mid = low + (high-low)/2;

        if(ar[mid]==target)
        return mid;

        else if(ar[mid]>target)
        high = mid-1;

        else
        low = mid+1;
    }

    return -1;

}


int main(int argc, char const *argv[])
{
    
    vector<int> arr = {7, 9, 1, 2 ,3};

    int target;
    cin>>target;

    int ans;
    int pivot = Pivot(arr);

    if(target<=arr[arr.size()-1] && target>=arr[pivot])
    ans = binSearch(arr, pivot , arr.size()-1, target);

    else
    ans = binSearch(arr, 0, pivot-1, target);
    
    cout<<"Element is at index:" << ans << endl;

    return 0;
}
