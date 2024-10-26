#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;


bool po4(int n){

	//Base case
	if(n==1)
	return true;


	if(n%4!=0)
	return false;

	else
	return po4(n/4);

}

int main(){


	int n;
	cin >> n;

	bool var = po4(n);
	if(var)
	cout << "Power" << endl;

	else
	cout << "Not Power" << endl;


	return 1;
}
