#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void pArr(vector<int> arr)
{

    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void insertionSort(vector<int> arr)
{
    int i = 1;
    
    for (; i < arr.size(); i++)
    {
        int temp = arr[i];
        int j = i-1;

        for(; j>=0; j--)
        {
            if(arr[j]>temp)
            arr[j+1] = arr[j];

            else
            break;                
        }
        arr[j+1] = temp;

        cout<<"After swap "<< i << ": ";
        pArr(arr);
    }
 
}

int main(int argc, char const *argv[])
{
    
    vector<int> arr = {5,4,3,2,1};

    insertionSort(arr);
    return 0;
}
