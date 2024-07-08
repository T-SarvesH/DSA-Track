// Question 2582- Pass the Pillow
// Description- https://leetcode.com/problems/pass-the-pillow/description/
// Difficulty- Easy

#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int fn(int start, int end, int time)
{

    bool dir = false;

    while (1)
    {
        cout<<"Person " << start <<" holding the Pillow" << endl;

        if(time==0)
        break;

        if(start==1)
        dir = true;

        if(start==end)
        dir = false;

        if(dir)
        start++;

        else
        start--;

        time--;
    }
    
    return start;
}
int main()
{

    int start = 1;

    int n;
    cin>>n;


    int time;
    cin>>time;

    int currHolding = fn(start, n, time);

}

