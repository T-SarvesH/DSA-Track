// First and last occurence of an element in array.
// Question on Code360 CodingNinjas

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

vector<int> Occurences(int ar[], int size, int target)

{
    
    int low = 0, i=0;
    int high = size-1;
    int mid;

    vector<int> ret;


    while(low<=high)
    {
        mid = low + (high-low)/2;

        cout<<"Step "<< i << " : ";
        Step(ar, low, high);

        if(ar[mid]==target)
        {
            int ans = ar[mid];
            if(ar[low]==ans && ar[high]==ans)
            {
                ret.push_back(low);
                ret.push_back(high);
                return ret;
            }
            

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

    ret.push_back(-1);
    ret.push_back(-1);
    return ret;
    
}


int main(int argc, char const *argv[])
{
    
    int arr[] = {0,0,1,1,2,2,2,2};
    int target = 2;

    vector<int> ans = Occurences(arr, 8, target);
    cout<<"The first and last occurence of "<< target << " is : ";

    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
    


    return 0;
}
