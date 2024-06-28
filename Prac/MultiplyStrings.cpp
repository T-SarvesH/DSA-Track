//43- Multiply Strings
//Difficulty- Medium
//Description- https://leetcode.com/problems/multiply-strings/description/

#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;

string mul(string num1, string num2)
{

    int i = 0;
    int k = 0;
    long long sum1 = 0;
    int n = num1.length()-1;
    int m = num2.length()-1;
    int j = m;

    while (i<=n)
    {
            long long ch = (num1[i] - '0') * pow(10, n-i);
            sum1 = sum1 + ch;
            i++;
    }

    long long int p1=0;
    while (j>=0)
    {
        long long p2 = sum1 * (num2[j] - '0') * pow(10,k);
        p1 = p1 + p2;
        j--;
        k++;
    }
    

    return(to_string(p1));
}


int main(int argc, char const *argv[])
{
    string s1 = "498828660196";
    string s2 = "840477629533";

    string res = mul(s1, s2);

    cout<<"Product is: "<< res << endl;

    return 0;
}
