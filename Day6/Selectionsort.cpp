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
void selectSort(vector<int>arr, int size)
{
    for (int i = 0; i < size-1; i++){
    
        cout<<"Step "<< i+1 << " :";
        printArr(arr, size);

        int index = i;

        for (int j = i+1; j<size; j++)
        {
            if(arr[j]<arr[index])
            {
                index = j;
            }
        }
        swap(arr[i], arr[index]);
        
    }
    
}

int main(int argc, char const *argv[])
{
    
    vector<int> arr = {56,46,36,12,2};

    selectSort(arr, arr.size());
    return 0;
}
