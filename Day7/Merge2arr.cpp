#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

void merge(int arr1[], int arr2[], int n, int m)
{
    int i = 0, j=0;
    int k = 0;

    int ans[n+m];

    while (i<n && j<m)
    {
            if(arr1[i]<arr2[j])
            {
                ans[k++] = arr1[i++];
            }

      
            else
            {
                ans[k++] = arr2[j++];
                
            }
            
    }

    while (i<n)
    {
        ans[k++] = arr1[i++];
    }

    while (j<m)
    {
        ans[k++] = arr2[j++];
    }
    
    cout<<"The sorted array is: "<< endl;

    for (int i = 0; i < n+m; i++)
    {
        cout<<ans[i]<<" ";
    }
    
    
}


int main(int argc, char const *argv[])
{
    int ar1[]= {1,3,5,7,9};
    int ar2[]= {2,4,6,8};

    int n = sizeof(ar1)/sizeof(ar1[0]);
    int m = sizeof(ar2)/sizeof(ar2[0]);

    merge(ar1, ar2, n, m);
    
    return 0;
}
