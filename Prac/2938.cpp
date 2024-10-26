#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int main(){


	string s = "0111";
	long long count = 0;
	int c = 0;

	for(int i= s.size()-1;i>=0; i--){
	
	if(s[i]=='0')
	c++;

	else{

	count+=c;
	c = 0;
	}

	}


	cout << count << endl;
	return 0;
}
