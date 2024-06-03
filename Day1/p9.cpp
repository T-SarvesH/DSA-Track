#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int row_c;
    cin>>row_c;

    int i = 0;

    while (i<row_c)
    {
        int space_count = 0;
        while (space_count<i)
        {
            cout<<" ";
            space_count = space_count +1;
        }

        int star_count = row_c;

        while (star_count>i)
        {
            cout<<"*";
            star_count = star_count - 1;
        }
        cout<<endl;
        i = i+1;
        
    }
    
    return 0;
}
