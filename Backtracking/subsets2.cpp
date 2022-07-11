class Solution {
    void solve(int i, int n, vector<int> &nums,vector<vector<int> > &ans, vector<int> &t){
        if(i==n){
            ans.push_back(t);
            return;
        }
        
        int j = i+1;
        while(j<n && nums[j]==nums[i]){
            j++;
        }
        solve(j, n, nums, ans, t);
        
        t.push_back(nums[i]);
        solve(i+1, n, nums, ans, t);
        t.pop_back();
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int> > ans;
        vector<int> t;
        solve(0, n, nums, ans, t);
        return ans;
    }
};