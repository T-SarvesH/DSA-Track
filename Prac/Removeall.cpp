#include<stdio.h>
#include<bits/stdc++.h>
#include<iostream>
// #include<cctype>

using namespace std;

void decode(string &s, string &ans, stack<char> &chr, stack<char> &data){

    string temp = "";
    while(chr.top()!='['){

        temp.push_back(chr.top());
        chr.pop();
    }

    reverse(temp.begin(), temp.end());

    for(int i = data.top()-'0'; i>=1; --i)
    ans = ans + temp;

    chr.pop();
    data.pop();
}

string parse(string &s, string &ans){

    stack<char> chr;
    stack<char> data;

    for(char ch: s){

        if(isdigit(ch))
        data.push(ch);

        else if(isalpha(ch) || ch=='[')
        chr.push(ch);
        
        else
        decode(s, ans, chr, data);
    }
    return ans;
    
}

int main(int argc, char const *argv[])
{
    string s = "3[a]2[bc]";
    string ans = "";
    ans = parse(s, ans);

    // reverse(ans.begin(), ans.end());
    cout << ans << endl;

    return 0;
}
