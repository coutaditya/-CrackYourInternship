// We use bits to store the cities that have been visited instead of a visited array, thus enabling us to use it as a DP state

#include<bits/stdc++.h>

#define int long long int
#define ff first
#define ss second
#define pb push_back
#define pii pair<int, int>

using namespace :: std;

// NOTE: Here using DP we converted the TC from O(n^n) to O(2^n*(n*n))

int tsp(vector<vector<int> > dist, int setOfCities, int city, int n, vector<vector<int> > &dp){
	if(setOfCities==((1<<n)-1)){
		return dist[city][0];
	}

	if(dp[setOfCities][city]!=-1){
		return dp[setOfCities][city];
	}

	int ans = INT_MAX;

	for(int choice=0; choice<n; choice++){
		if((setOfCities & (1<<choice))==0){
			int subProb = dist[city][choice] + tsp(dist, (setOfCities|(1<<choice)), choice, n, dp);
			ans = min(ans, subProb);
		}
	}
	return dp[setOfCities][city] = ans;
}

int32_t main(){

	vector<vector<int> > dist = {
		{0,5,10,7},
		{6,0,11,5},
		{8,5,0,6},
		{9,4,11,0}
	};

	int n=4;

	vector<vector<int> > dp((1<<n), vector<int>(n, -1));

	cout<<tsp(dist, 1, 0, 4, dp);
	
	return 0;
}