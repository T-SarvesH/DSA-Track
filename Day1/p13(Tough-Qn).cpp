#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int row_c;
    cin>>row_c;

    int i = 0;

    while (i<row_c)
    {
        int j = 1;

        while (j<=row_c-i)
        {
            cout<<j;
            j = j+1;
        }
        
        //Star pattern
        
        int stars = 0;

        while (stars<i)
        {
            cout<<"*";
            stars = stars + 1;
        }

        stars = 0;
        while (stars<i)
        {
            cout<<"*";
            stars = stars + 1;
        }

        int co = row_c-i;
        while (co)
        {
            cout<<co;
            co = co - 1;
        }
     
        cout<<endl;
        i = i+1;
        
    }
    
    return 0;
}
