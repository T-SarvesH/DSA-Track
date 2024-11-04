#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
#include<string.h>

using namespace std;

bool circularSentence(string sentence){


	for(int i=0; i<sentence.size(); i++){

		if(sentence[i]==' ' && sentence[i+1]!=sentence[i-1])
		return false;
	}

	return true;
}

int main(){
	
	string sentence;
	getline(cin, sentence);

	int n = sentence.size();

	if (sentence[0]!=sentence[n-1])
	cout << "Not circular" << endl;

	else{
		
		if(circularSentence(sentence))
		cout << "Circular" << endl;

		else
		cout << "Not Circular" << endl;
	}
	
	return 0;
}
