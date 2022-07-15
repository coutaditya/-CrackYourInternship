class Solution {
    int dx[4] = {-1,0,0,1};
    int dy[4] = {0,-1,1,0};
    
    void dfs(int i, int j, int n, int m, vector<vector<int> > &matrix, vector<vector<int> > &length, int &ans){
        length[i][j] = 1;
        for(int x = 0; x < 4; x++){
            int xx = i+dx[x];
            int yy = j+dy[x];
            
            if(xx<n && xx>=0 && yy<m && yy>=0 && matrix[i][j]<matrix[xx][yy]){
                if(length[xx][yy]==0) dfs(xx, yy, n, m, matrix, length, ans);
                length[i][j] = max(length[i][j], 1+length[xx][yy]);
            }
        }
        
        ans = max(length[i][j], ans);
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int> > length(n, vector<int>(m, 0));
        int ans = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(length[i][j]==0){
                    dfs(i, j, n, m, matrix, length, ans);
                }
            }
        }
        
        return ans;
    }
};