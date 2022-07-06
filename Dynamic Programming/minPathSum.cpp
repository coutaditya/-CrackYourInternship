// Space optimised tabulation

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> prev(m, 0);
        
        prev[0] = grid[0][0];
        for(int i=1; i<m; i++){
            prev[i] = prev[i-1]+grid[0][i];
        }
        
        for(int i=1; i<n; i++){
            vector<int> cur(m, 0);
            cur[0] = prev[0]+grid[i][0];
            for(int j=1; j<m; j++){
                cur[j] = min(prev[j], cur[j-1])+grid[i][j];
            }
            
            prev = cur;
        }
        
        return prev[m-1];
    }
};