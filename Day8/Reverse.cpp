#include<stdio.h>
#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    char n[50];

    cout<<"Enter your name: "<<endl;
    cin>> n;

    int i = 0;
    while(n[i+1]!='\0')
    i++;

    int low = 0;
    while(low<=i)
    {
        swap(n[low], n[i]);
        i--;
        low++;
    }

    cout<<"Reverse string is: "<<n<<endl;

    
    return 0;
}
