#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>

using namespace std;

bool cmp(pair<char, int>a, pair<char,int>b)
{
    return a.second < b.second;
}

void Mini(string word)
{
    if(word.size()<=8)
    cout<<word.size()<<endl;

        map<char, int> freq;
        int c = 0;

        vector<pair<char, int>> temp;

        for(auto ch: word)
        freq[ch]++;

        for(auto &it: freq)
        temp.push_back(it);        

        sort(temp.rbegin(), temp.rend(), cmp);

        int c1=1;
        int cn = 2;
        
        for(auto &i: temp){
            
            if(cn==10)
            {
                c1++;
                cn = 2;
            }

            c += (c1*i.second);
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
