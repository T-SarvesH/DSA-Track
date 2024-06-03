#include<stdio.h>
#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    
    int n;
    cin>>n;
    int i = 2, sum = 0;

    while (i<=n)
    {
        if(i%2==0)
        sum = sum + i;

        i = i+1;
    }
    cout<<"Sum is: "<<sum<<endl;
    return 0;
}
