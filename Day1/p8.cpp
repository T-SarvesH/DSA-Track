#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int row_c;
    cin>>row_c;

    int i = 0;

    while (i<row_c)
    {
        int count = row_c;

        while (count>i)
        {
            cout<<"*";
            count = count - 1;
        }
        cout<<endl;
        i = i+1;
        

    }
    
    return 0;
}
