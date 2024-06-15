#include<iostream>
#include<math.h>
#include<string.h>

using namespace std;

int colNumber(string s, int size)
{
    
    int ans = 0;
    size--;
    int i = 0;

    while (size>=0)
    {
        ans = ans + pow(26,size)*((int)s[i]%64);
        i++;
        size--;
    }
    return ans;
    
}

int main(int argc, char const *argv[])
{
    string s = "AB";

    cout<<"The Excel column number for "<<s<<" is: " <<colNumber(s, s.length())<<endl;

    return 0;
}
