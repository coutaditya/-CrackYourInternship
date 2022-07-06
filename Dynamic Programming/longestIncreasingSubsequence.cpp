// O(n^2) tabulation solution

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n, 1);
        
        int ans = 1;
        
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]>nums[j]){
                    t[i] = max(t[i], t[j]+1);
                    ans = max(ans, t[i]);
                }
            }
        }
        
        return ans;
    }
};

// Monotonic stack solution
// https://leetcode.com/problems/longest-increasing-subsequence/discuss/2246097/C%2B%2B-Monotonic-Stack-and-Why-does-it-work
// Read the beautiful explanation
// TC: O(nlog(n)) SC: O(n)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> s;
        
        for(int i = 0; i<n; i++){
            if(s.size()==0 || s[s.size()-1]<nums[i]){
                s.push_back(nums[i]);
            }
            else{
                auto it = lower_bound(s.begin(), s.end(), nums[i]);
                *it = nums[i];
            }
        }
        
        return s.size();
    }
};
