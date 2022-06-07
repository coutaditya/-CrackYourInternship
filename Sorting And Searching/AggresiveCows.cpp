// Standard Binary Search on Answer Problem
// for the search space, the min distance between two stalls is lower limit and upper limit will be (end-point stalls)/(no. of cows-1)

#include<bits/stdc++.h>

#define int long long int
#define ff first
#define ss second
#define pb push_back
#define pii pair<int, int>

using namespace :: std;

bool check(vector<int> v, int x, int c){
	int s = 0;
	int i = 1;
	int cow = 1;
	while(i<v.size()){
		if((v[i]-v[s])>=x){
			cow++;
			s =  i;
		}
		i++;
	}

	if(cow<c){
		return false;
	}

	return true;
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t=0;
	cin>>t;
	while(t--){
		int n = 0, c = 0;
		cin>>n>>c;
		vector<int> v(n, 0);
		for(int i=0; i<n; i++){
			cin>>v[i];	
		}

		sort(v.begin(), v.end());
		int s = INT_MAX;

		for(int i=1; i<n; i++){
			if(v[i]-v[i-1]<s){
				s=v[i]-v[i-1];
			}
		}

		int e = (v[n-1]-v[0])/(c-1);
		int ans = -1;

		while(s<=e){
			int mid = s+(e-s)/2;

			if(check(v, mid, c)){
				ans = mid;
				s=mid+1;
			}
			else{
				e = mid-1;
			}
		}

		cout<<ans<<"\n";
	}
	return 0;
}