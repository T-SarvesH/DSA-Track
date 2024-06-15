// Bubble Sort using C++

//Selection Sort in C++
//

#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

void printArr(vector<int> arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}
void bubSort(vector<int>arr, int size)
{
    for (int i = 0; i < size-1; i++){
    
        for (int j = 0; j<size-i; j++)
        {
            if(arr[j]>arr[j+1] && j+1<arr.size()) 
            swap(arr[j], arr[j+1]);
        }

        cout<<"After Step "<< i+1 << " :";
        printArr(arr, size);
           
    }
}

int main(int argc, char const *argv[])
{
    
    vector<int> arr = {56,46,36,12,2};

    bubSort(arr, arr.size());
    return 0;
}

