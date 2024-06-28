#include<stdio.h>
#include<iostream>

using namespace std;

char convert(char ap)
{
    if(ap>='a' && ap<='z')
    return ap;

    else{

        ap = ap - 'A' + 'a';
        return ap;
    }
}


bool pal(char s[])
{

    int i = 0;
    while(s[i+1]!='\0')
    i++; 

    int low = 0;

    while(low<=i)
    {
        if(tolower(s[low])!=tolower(s[i]))
        return false;
        
        else
        {
            if(!isalpha(s[low]))
            low++;

            if(!isalpha(s[i]))
            i--;
        
        }
    
    }

    return true;
}

int main(int argc, char const *argv[])
{
    char n[50];

    cout<<"Enter your name: "<<endl;
    cin>> n;

    if(pal(n))
    cout<<"Palindrome"<<endl;

    else
    cout<<"Not Palindrome"<<endl;

    return 0;
}
