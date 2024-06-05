// Fibonacci series using function

#include<iostream>
#include<stdio.h>

using namespace std;

void Fibonacci(int n)
{
    int t1 = 0;
    int t2 = 1;
    int t3;

    for (int i = 2; i < n; i++)
    {
        t3 = t2 + t1;
        t1 = t2;
        t2 = t3;
    }
    
    cout<<"nth Fibonacci term is: "<<t3<<endl;
    
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;

    Fibonacci(n);    
    return 0;
}
