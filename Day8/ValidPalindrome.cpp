// Question 125- Valid Palindrome
// Difficulty- Easy
// Description- https://leetcode.com/problems/valid-palindrome/description/

#include<stdio.h>
#include<iostream>

using namespace std;

bool valid(char ap)
{

    if((ap>='a' && ap<='z')||(ap>='A' && ap<='Z')||(ap>='0' && ap<='9'))
    return true;

    return false;

}

bool valid2(string t)
{

    int i = t.size()-1;
    int low = 0;

    while(low<i)
    {
        if(t[low]!=t[i])
        return false;
        
        low++;
        i--;
    
    }
    return true;
}

int main(int argc, char const *argv[])
{   
    string s;
    cin>>s;

    string t = "";

    for(int j = 0; j<s.size(); j++)
    {
        if(valid(s[j]))
        t.push_back(tolower(s[j]));
    }
    
    if(valid2(t))
    cout<<"Valid Palindrome! "<<endl;

    else
    cout<<"Not a Valid Palindrome! "<<endl;

    return 0;
}
