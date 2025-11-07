#include<bits/stdc++.h>

using namespace std;

int main(){

    long long int n, x;
    cin >> n;
    
    vector<long long int> series;

    for(int i=1; i<=n; ++i)
        series.push_back(i);
    
    for(int i=0; i<n-1; ++i){

        cin >> x;
        series.push_back(x);
    }

    long long int ans = 0;
    for(int i=0; i<series.size(); ++i)
        ans^=series[i];
    
    cout << ans << endl;
    
    return 0;
}