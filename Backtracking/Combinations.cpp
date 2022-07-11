// Backtracking solution
// NOTE: Backtracking improves space and time complexity by avoiding some recursive function calls
//       So always backtrack by yourself instead of using recursive function calls to bactrack

class Solution {
public:
    void solve(int n, int k, int i, vector<vector<int> > &ans, vector<int> t){
        if(k==0){
            ans.push_back(t);
            return;
        }
        
        if(i>n){
            return;
        }
        
        for(int j = i; j<=n; j++){
            t.push_back(j);
            solve(n, k-1, j+1, ans, t);
            t.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > ans;
        vector<int> t;
        solve(n, k, 1, ans, t);
        return ans;
    }
};