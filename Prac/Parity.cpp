//Qn 905 Sort Array by Parity - LeetCode
//Approach is 2-Pointers

#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

void priArr(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    cout<<arr[i]<<" ";

    cout<<endl;  
}

void Par(vector<int> arr)
{
    int low = 0;
    int high = arr.size()-1;

    while (low<=high)
    {
        if(arr[low]%2!=0)
        {
            if(arr[high]%2==0)
            {
                swap(arr[high], arr[low]);
                high--;
                low++;
            }
            
            else
            low++;
        }

        else{

            if(arr[high]%2==0)
            low++;

            else
            high--;
        }

        priArr(arr);
    }

    cout<<"The Final array is: ";
    priArr(arr);
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {3,1,2,4};

    Par(arr);

    return 0;
}
