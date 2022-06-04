#include<bits/stdc++.h>

#define int long long int
#define ff first
#define ss second
#define pb push_back
#define pii pair<int, int>

using namespace :: std;

int Ceil(vector<int> A, int k){
	int n = A.size();
	int s = 0, e = n-1;
	while(s<=e){
		int mid = s+(e-s)/2;
		if(A[mid]<k){
			s=mid+1;
		}
		else if(A[mid]==k){
			return k;
		}
		else{
			e=mid-1;
		}
	}
	if(s!=n){
		return A[s];
	}
	else{
		return -1;
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	vector<int> A = {1,2,5,6,6,8,9,10,14};

	cout<<Ceil(A,6)<<"\n";
	cout<<Ceil(A,15)<<"\n";
	cout<<Ceil(A,3)<<"\n";
	cout<<Ceil(A,0)<<"\n";


	return 0;
}