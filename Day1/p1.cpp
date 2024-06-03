#include<iostream>
#include<stdio.h>

using namespace std;

int main(int argc, char const *argv[])
{
    
    int row_count;
    cin>>row_count;

    int i=0;
    int count = 1;
    while(i<row_count)
    {
        
        int j=0;
        while (j<=i)
        {
            cout<<count<<" ";
            count = count + 1;
            j = j+1;
        }
        cout<<endl;

        i = i+1;
        
    }
    return 0;
}
