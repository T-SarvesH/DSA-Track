#include<stdio.h>
#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    char n[50];

    cout<<"Enter your name: "<<endl;
    cin>> n;

    int i = 0;
    while(n[i]!='\0')
    i++;

    cout<<"Length is: "<<i<<endl;
    
    return 0;
}
