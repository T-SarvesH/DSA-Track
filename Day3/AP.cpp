// Arithmetic progression using functions


#include<stdio.h>
#include<iostream>

using namespace std;

int AP(int n)
{
    return (3*n+7);
}

int main(int argc, char const *argv[])
{

    int n;
    cin>>n;
    
    cout<<"nth term of AP is: "<<AP(n);
    return 0;

    
}

