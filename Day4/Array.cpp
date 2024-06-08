#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int main(int argc, char const *argv[])
{

    int array[1000];

    fill_n(array,1000, 1); //Method to fill entire or some part of array with same value
    

    int n = sizeof(array)/sizeof(array[0]);
    for (int i = 0; i < n; i++)
    {
        cout<<array[i]<<" ";
    }
    
    return 0;
}
