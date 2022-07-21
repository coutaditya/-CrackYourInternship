class Solution {
public:
    void solve(int id, vector<int> &nums, vector<vector<int> > &ans, vector<int> &t){
        if(id==nums.size()){
            ans.push_back(t);
            return;
        }
        
        solve(id+1, nums, ans, t);
        
        t.push_back(nums[id]);
        
        solve(id+1, nums, ans, t);
        
        t.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> t;
        
        solve(0, nums, ans, t);
        return ans;
    }
};