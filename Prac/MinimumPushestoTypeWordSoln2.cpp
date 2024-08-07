#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>

using namespace std;

void Mini(string word)
{
        if(word.size()<=8)
        cout<<word.size()<<endl;

        vector <int> f(26);

        for(auto ch: word)
        {
            char ch1 = ch - 'a';
            f[ch1]++; 
        }        

        sort(f.rbegin(), f.rend());

        int c1 = 1;
        int cn = 2;
        int c = 0;
        
        for(int i=0; i<f.size(); i++){
            
            if(cn==10)
            {
                c1++;
                cn = 2;
            }

            c += (c1*f[i]);
            cn++;
        }

        cout<<"Minimum pushes: " << c << endl;
        
}

int main(int argc, char const *argv[])
{
    string word;
    cin>>word;
    Mini(word);
    return 0;
}
