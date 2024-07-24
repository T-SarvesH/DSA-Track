#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>

using namespace std;

int countPrimes(int number)
{
    vector<bool> val(number+1, true);
    
    int t = 0;
    val[0] = val[1] = false;

    for (int i = 2; i < number; i++)
    {
        if(val[i])
        {
            t++;
            
            for(int j = 2*i; j < number; j=j+i)
            val[j] = 0;
        }
    }

    return t;
}

int main(int argc, char const *argv[])
{
    int number;
    cin>>number;

    int ct = countPrimes(number);

    cout<<"Number of primes less than "<< number << " are "<< ct << endl;
    return 0;
}

