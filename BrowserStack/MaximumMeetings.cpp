#include<bits/stdc++.h>
#define ll long long
#define li long int
#define pb push_back
#define pob pop_back
#define sz size
#define v vector
#define ump unordered_map
#define mp map
#define uset unordered_set
#define oset ordered_set

using namespace std;

template<typename T> T my_max(T x, T y){
	return x >= y? x: y;
}

template<typename T> T my_min(T x, T y){
	return x >= y? y: x;
}

int helper(v<int>&start, v<int>&end){

	int n = start.sz();
	// Use pairs of {end, start} to sort by end time automatically
	v<pair<int, int>> intervals;

	for(int i=0; i<n; ++i)
		intervals.pb({end[i], start[i]});
	
	// O(N log N) sorting is required for the greedy strategy
	sort(intervals.begin(), intervals.end());

	int count = 0;
	int last_finish_time = -1;

	for(int i=0; i<n; ++i){
		// Greedy Choice: If current meeting start > last meeting end
		if(intervals[i].second > last_finish_time){
			count++;
			last_finish_time = intervals[i].first;
		}
	}
	
	return count;
}

int main(){
	
	int n;
	cin >> n;
	v<int> start(n); v<int> end(n);

	for(int i=0; i<n; ++i) cin >> start[i];
	for(int i=0; i<n; ++i) cin >> end[i];

	cout << helper(start, end) << endl;
	return 0;
}
