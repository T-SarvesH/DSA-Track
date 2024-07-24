#include<stdio.h>
#include<iostream>
#include<string.h>
#include<bits/stdc++.h>

using namespace std;

void stacktop(stack<char> s)
{
    cout << s.top() << endl;
}

bool valParent(string s)
{

    stack <char> st;

        //If size odd then definitely a parentheses is missing
        if(s.size()%2!=0)
        return false;

        for (int i = 0; i < s.size(); i++)
        {
            if(s[i]=='{' || s[i] =='(' || s[i]=='[')
            st.push(s[i]);
            
            else
            {
                char temp = char(s[i]);
                
                //If stack empty then definitely open char not present
                if(st.empty())
                return false;

                else if((temp-st.top() ==1) || (temp-st.top() == 2))
                st.pop();

                else
                return false;
            }
        }
        
        if(st.empty())
        return true;
            
        return false;
    
}
int main(int argc, char const *argv[])
{
    
    string s;

    cin>> s;

    bool val = valParent(s);
    cout<< "Valid Parentheses? --> " << val << endl;

    return 0;
}
