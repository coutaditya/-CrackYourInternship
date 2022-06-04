// This code is to check if such a permutation is possible.
// After checking if it is possible
// To create such a permutation, we create as (a sorted) and bs (b reverse sorted).
// For every a[i], we will find it in as (binary search) and check if corres bs ele is != -1 (-1 signifies that this ele has been taken)
// then we put b[i] = that ele, if ele == -1, we move right till ele != -1 and then put it
// we make the ele = -1, in bs array
// TC: O(nlogn) SC: O(n)


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

bool comp(long long a, long long b){
    return a>b;
}
class Solution {
  public:
    bool isPossible(long long a[], long long b[], long long n, long long k) {
        vector<long long> as(n, 0);
        vector<long long> bs(n, 0);
        for(int i=0; i<n; i++){
            as[i]=a[i];
            bs[i]=b[i];
        }
        
        sort(as.begin(), as.end());
        sort(bs.begin(), bs.end(), comp);
        
        for(int i=0; i<n; i++){
            if(as[i]+bs[i]<k){
                return false;
            }
        }
        
        return true;
    }
};

// { Driver Code Starts.
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        long long a[n + 2], b[n + 2];
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        Solution ob;
        cout << ob.isPossible(a, b, n, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends