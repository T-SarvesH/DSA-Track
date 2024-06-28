//1047- Remove all adjacent duplicates in string
// Difficulty- Easy 
// Approach- Two While loops and string functions (Not Optimised tbh)
// Description- https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/

#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

string removeDuplicates(string s)
{
    
    while (s.length()!=0)
    {
        int i = 0;

        while(i<s.length())
        {
            if(s[i]==s[i+1])
            {
                s.erase(i, 2);
                break;
            }
            i++;
        }

        if(i==s.length())
        break;
    }
    
    return s;
}

int main(int argc, char const *argv[])
{
    
    string s = "abbaca";
    
    cout<<"String before: "<< s <<endl;

    s = removeDuplicates(s);

    cout<<"String after: "<< s << endl;

    return 0;
}
