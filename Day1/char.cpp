#include<iostream>
#include<stdio.h>

using namespace std;

int main(int argc, char const *argv[])
{
    
    char ch;
    
    cout<<"Enter the character: "<< endl;
    cin>>ch;

    if (ch>='A' and ch <='Z')
    cout<<"Uppercase";

    else if(ch>='a' and ch<='z')
    cout<<"Lowercase";

    else if (ch>='0' and ch<='9')
    cout<<"Numeric";

    else
    cout<<"Special character";        
    
    return 0;
}
