#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main(int argc, char const *argv[])
{

    string s = "RoronoaZoro";
    string Find;

    cin>>Find;
    
    cout<<"Before Erase: "<<s<<endl;

    cout<<s.find(Find)<<endl;
    int index = s.find(Find);


    s.erase(index, Find.length());
    
    cout<<"After erase: "<<s<<endl;

    return 0;
}
