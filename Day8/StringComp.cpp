// //443- String Compression
// Difficulty- Medium, Approach- String manipulation
// Description- https://leetcode.com/problems/string-compression/description/

#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int compress(string chars)
{

    int i = 0;
    int id = 0;

    while (i<chars.length())
    {
        int j = i+1;
        int count = 0;

        while (j<chars.length() && chars[i]==chars[j])
        {
            j++;
        }
        
        chars[id++] = chars[i];
        count = j-i;

        if(count>1)
        {
            string tp = to_string(count);

            for(int k = 0; k<tp.length(); k++)
            chars[id++] = tp[k]; 
        }
        
        i = j;
    }

    return id;

}


int main(int argc, char const *argv[])
{
    string chars = "aabbbccc";

    int l = compress(chars);

    cout<<"Length of String compressed is: " << l << endl;

    return 0;
}
