//28- Find first occurence in a string
// Difficulty- Easy
// Description- https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[])
{
    string haystack;
    string needle;

    cin>>haystack>>needle;

    int index = haystack.find(needle);

    if(index==-1)
    cout<<"Not Found!"<<endl;

    else
    cout<<"First Ocuurence at index: "<< index << endl;
    return 0;
}
