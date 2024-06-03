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
            space_count = space_count + 1;
        }

        
        int s = i+1;
        while (s<=row_c)
        {
            cout<<s;
            s = s + 1;
        }
        cout<<endl;
        i = i+1;
        
    }
    
    return 0;
}
