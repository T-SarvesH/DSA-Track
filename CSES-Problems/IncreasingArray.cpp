#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    long long int x;
    vector<long long int> array;
    cin >> n;

    for(int i=0; i<n; ++i){

        cin >> x;
        array.push_back(x);
    }

    long long int dif = 0; long long int minMoves = 0;

    for(int i=1; i<n; i++){

        if(array[i] < array[i-1]){

            dif = array[i-1] - array[i];
            minMoves += dif;
            array[i] += dif;
        }

    }

    cout << minMoves << endl;
    return 0;
}