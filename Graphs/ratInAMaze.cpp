// Standard backtracking while using dfs to explore paths

class Solution{
    public:
    void dfs(vector<vector<int> > &mat, int i, int j, int n, int m, vector<vector<bool> > &vis, string &s, vector<string> &ans){
        if(i==n || i==-1 || j==-1 || j==m || mat[i][j]==0 || vis[i][j]){
            return;
        }
        if(i==n-1 && j==m-1){
            ans.push_back(s);
            return;
        }
        
        vis[i][j] = true;
        
        s.push_back('D');
        dfs(mat, i+1, j, n, m, vis, s, ans);
        s.pop_back();
        s.push_back('R');
        dfs(mat, i, j+1, n, m, vis, s, ans);
        s.pop_back();
        s.push_back('U');
        dfs(mat, i-1, j, n, m, vis, s, ans);
        s.pop_back();
        s.push_back('L');
        dfs(mat, i, j-1, n, m, vis, s, ans);
        s.pop_back();
        
        vis[i][j] = false;
    }
    
    vector<string> findPath(vector<vector<int>> &mat, int N) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<string> ans;
        
        vector<vector<bool> > vis(n, vector<bool>(m, false));
        
        if(mat[0][0]==0) return ans;
        
        string s="";
        
        dfs(mat, 0, 0, n, m, vis, s, ans);
        
        return ans;
    }
};