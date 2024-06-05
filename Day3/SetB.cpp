// Finding number of set bits of 2 numbers using Functions

#include<iostream>
#include<stdio.h>

using namespace std;

int setBits(int n1, int n2)
{
    int count = 0;

    while(n1!=0 || n2!=0)
    {
        
        int b1 = n1 & 1;
        int b2 = n2 & 1;

        if(b1==1 || b2==1)
        {
            if(b1==b2)
            count+=2;

            else
            count++;
        }
        
        n1 = n1>>1;
        n2 = n2>>1;
    }

    return count;
}
int main(int argc, char const *argv[])
{
    
    int a, b;

    cin>>a>>b;

    cout<<"Total number of set bits in a and b are: "<< setBits(a,b)<<endl;
    return 0;
}
