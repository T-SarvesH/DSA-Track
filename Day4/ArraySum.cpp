#include<iostream>
#include<stdio.h>

using namespace std;

int main(int argc, char const *argv[])
{
    
    int size;
    cin>>size;

    int arr[100];
    int sum=0;
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    cout<<"The sum is: "<< sum << endl;
    
    return 0;
}
