#include<bits/stdc++.h>

#define int long long int
#define ff first
#define ss second
#define pb push_back
#define pii pair<int, int>

using namespace :: std;

int minCoins(vector<int> coins, int k){
	int n = coins.size();

	sort(coins.begin(), coins.end());

	int ans = 0;
	int i = 0;
	while(i<coins.size() && n>0){
		ans+=coins[i];
		n-=(k+1);
		i++;
	}

	return ans;
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	vector<int> coins = {10, 20, 50, 100, 2, 5};
	int k = 3;
	cout<<minCoins(coins, k);
	return 0;
}