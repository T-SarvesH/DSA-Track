#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int row_c;
    cin>>row_c;

    int i = 0;

    while (i<row_c)
    {
        int j = 0;
        while (j<=i)
        {
            char s = 'A'+i;
            cout<< s ;
            j = j+1;
        }
        cout<<endl;
        i = i+1;

    }
    
    return 0;
}
