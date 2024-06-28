//Question 1910- Remove all occurences of a substring from a string
// Difficulty- Medium
// Description- https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/

#include<stdio.h>
#include<iostream>

using namespace std;


string removeAll(string s, string part)
{
    while(s.length()!=0 && s.length()>=part.length())  //Another condition
    {
        int index = s.find(part);

        if(index==-1)
        break;
        
        s.erase(index, part.length());

    }
    cout<<endl;
    return s;
}


int main(int argc, char const *argv[])
{
    string s;
    string part;

    cin>>s>>part;
    
    cout<<"String before: "<<s<<endl;

    s = removeAll(s, part);

    cout<<"String after: "<<s<<endl;

    return 0;
}
