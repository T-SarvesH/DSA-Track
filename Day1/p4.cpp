#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int row_c;
    cin>>row_c;

    char s = 'A';

    int i = 0;

    while (i<row_c)
    {
        int j = 0;
        while (j<row_c)
        {
            cout<<s;
            s = s + 1; //RHS converted into ascii val and after oprn,reconverted to corresponding char of value as 's' is a character
            j = j+1;
        }
        cout<<endl;
        i = i+1;
        
    }
    
    return 0;
}
