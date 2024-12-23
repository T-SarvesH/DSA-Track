#include <bits/stdc++.h>
using namespace std;

int sameDif(vector<int> &nums) {
    unordered_map<int, int> freq;
    int count = 0;

    for (int i = 0; i < nums.size(); i++) {
        int diff = nums[i] - i;
        count += freq[diff]; 
        freq[diff]++;        
    }

    return count;
}

int main() {
    int t;
    cin >> t;

    vector<int> ans(t);
    for (int k = 0; k < t; k++) {
        int n;
        cin >> n;
        vector<int> nums(n);
        
        for (int i = 0; i < n; i++) 
        cin >> nums[i];
        
        ans[k] = sameDif(nums);
    }

    for (int i = 0; i < t; i++)
    cout << ans[i] << endl;
    

    return 0;
}

