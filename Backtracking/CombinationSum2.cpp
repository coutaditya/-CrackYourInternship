// Backtracking Solution without using a set to get unique subsequences

class Solution {
public:
    void solve(vector<int> &v, int tar, int i, int sum, vector<vector<int> > &ans, vector<int> t){
        if(sum==tar){
            ans.push_back(t);
            return;
        }
        if(sum>tar || i>=v.size()) return;
        
        
        int j = i;
        while(j<v.size() && v[j]==v[i]){
            j++;
        }
        solve(v, tar, j, sum, ans, t);
        t.push_back(v[i]);
        solve(v, tar, i+1, sum+v[i], ans, t);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > ans;
        vector<int> t;
        solve(candidates, target, 0, 0, ans, t);
        return ans;
    }
};

// Sligtly better solution (avoids some Auxiliary Stack Space)

class Solution {
public:
    void solve(vector<int> c, int sum, int target, int i, int n, vector<int> v, vector<vector<int> > &ans){
        if(sum==target){
            ans.push_back(v);
            return;
        }
        if(sum>target){
            return;
        }
        
        if(i==n){
            return;
        }
        
        v.push_back(c[i]);
        solve(c, sum+c[i], target, i+1, n, v, ans);
        v.pop_back();
        
        for(int j=i+1; j<n; j++){
            if(c[j-1]!=c[j]){
                v.push_back(c[j]);
                solve(c, sum+c[j], target, j+1, n, v, ans);
                v.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<vector<int> > ans;
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        solve(candidates, 0, target, 0, n, v, ans);
        return ans;
    }
};