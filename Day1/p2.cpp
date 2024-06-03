#include<stdio.h>
#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    
    int row_count;
    cin>>row_count;

    int i=1;

    while (i<=row_count)
    {
        int j = 1;

        while (j<=i)
        {
            cout<<i+j-1<<" ";
            j = j+1;
        }
        
        cout<<endl;
        i = i+1;
    }
    
    return 0;
}
