#include<vector>
#include<iostream>
#include<stdio.h>

using namespace std;

bool binSearch(vector<int>ans, int low, int high, int target){

    int mid;

    while (low<=high)
    {
        mid = low + (high-low)/2;
        if(ans[mid]==target)
        return true;

        else if(ans[mid]>target)
        high = mid-1;

        else
        low = mid+1;
    }
    return false;
    

}


int main(int argc, char const *argv[])
{
    
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int tar;

    cin>>tar;

    int n = matrix.size();
    int m = matrix[0].size();

    int low = 0;
    int high = n;
    int mid;

    while (low<=high)
    {
        mid = low + (high-low)/2;

        if (tar==matrix[mid][0])
        return true;

        else if(tar>matrix[mid][0] && tar < matrix[mid][m-1])
        return binSearch(matrix[mid], 0, m-1, tar);

        else if(tar<matrix[mid][0])
        high = mid-1;

        else
        low = mid+1;
             
        
    }
    

    return 0;    
}
