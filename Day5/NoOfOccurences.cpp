// Number of occurences of an element in array.

#include<iostream>
#include<stdio.h>
#include<vector>


using namespace std;

void Step(int ar[], int x, int y)
{
    for (int i = x; i<=y; i++)
    {
        cout<< ar[i] << " "; 
    }

    cout<< endl;
    
}

int Occurences(int ar[], int size, int target)

{
    
    int low = 0, i=0;
    int high = size-1;
    int mid;

    while(low<=high)
    {
        mid = low + (high-low)/2;

        cout<<"Step "<< i << " : ";
        Step(ar, low, high);

        if(ar[mid]==target)
        {
            int ans = ar[mid];
            if(ar[low]==ans && ar[high]==ans)
            break;
    
            else if(ar[low]<ans)
            low++;

            else
            high--;

        }

        else if(ar[mid]>target)
        {
            high = mid-1;
        }

        else{
            low = mid+1;
        }

        i++;
    }

    return (high-low)+1;
    
}


int main(int argc, char const *argv[])
{
    
    int arr[] = {0,0,1,1,2,2,2,2};
    int target = 2;

    int ans = Occurences(arr, 8, target);
    cout<<"No of occurences of target are: "<< ans << endl;;

    return 0;
}
