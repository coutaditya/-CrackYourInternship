// TC: O(n) SC: O(1)

#include<bits/stdc++.h>

#define int long long int
#define ff first
#define ss second
#define pb push_back
#define pii pair<int, int>

using namespace :: std;

bool check(vector<int> v){
	int n = v.size();

	int i=0;
	while(i<n-1){
		if(v[i]<=v[i+1]){
			i++;
		}
		else{
			break;
		}
	}

	if(i==n-1){
		return true;
	}

	int j=i;
	i--;
	while(j<n-1 && v[j]>=v[j+1]){
		j++;
	}

	if(j==n-1){
		return true;
	}
	j++;

	if((i!=-1 && v[i]>v[j-1]) || v[j]<v[i+1]){
		return false;
	}

	while(j<n-1){
		if(v[j]>v[j+1]){
			return false;
		}
		j++;
	}

	return true;
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	vector<int> v = {5,4,3,2,1};
	cout<<check(v);
	return 0;
}