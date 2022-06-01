// 1D DP Solution: TC: O(n^2) SC: O(n)
// DP table t stores for each index i the maximum cost for array i to n-1;


// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int solveWordWrap(vector<int>nums, int k) 
    { 
        int n = nums.size();
        vector<int> t(n, 0); // t[i] stores the max cost of sentences for the array from i to n-1
        
        for(int i=n-2; i>=0; i--){
            int temp = (k-nums[i])*(k-nums[i])+t[i+1];
            int j = i+1;
            int sum = nums[i];
            while(j<n && (sum+nums[j]+1)<=k){
                sum+=nums[j]+1;
                if((j+1)!=n)
                    temp = min(temp, (k-sum)*(k-sum) + t[j+1]);
                else{
                    temp = 0;
                }
                j++;
            }
            
            t[i] = temp;
        }
        
        return t[0];
    } 
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}  // } Driver Code Ends