class Solution {
public:
    void solve(int i, int pi, vector<int> &nums, vector<int> &t, vector<vector<int> > &ans){
        if(i==nums.size()){
            ans.push_back(t);
            return;
        }
        
        int s = 0;
        if(nums[i]==nums[i-1]){
            s = pi+1;
        }
        
        for(int j=s; j<nums.size(); j++){
            if(t[j]==11){
                t[j] = nums[i];
                solve(i+1, j, nums, t, ans);
                t[j] = 11;
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> t(n, 11);
        
        for(int i=0; i<n; i++){
            t[i] = nums[0];
            solve(1, i, nums, t, ans);
            t[i] = 11;
        }
        
        return ans;
    }
};