class Solution {
    int free;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,-1,1};
public:
    void solve(vector<vector<int> >&grid, int i, int j, int &ans, int &cov){
        cov++;
        if(grid[i][j]==2 && cov==free){
            ans++;
            cov--;
            return;
        }
        
        int val = grid[i][j];
        grid[i][j] = 3;
        for(int x=0; x<4; x++){
            int xx = i+dx[x];
            int yy = j+dy[x];
            
            if(xx<grid.size() && xx>=0 && yy<grid[0].size() && yy>=0 && (grid[xx][yy]==0 || grid[xx][yy]==2)){
                solve(grid, xx, yy, ans, cov);
            }
        }
        cov--;
        grid[i][j] = val;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int obstacles = 0;
        int si = -1, sj = -1;
        for(int i=0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]==-1){
                    obstacles++;
                }
                if(grid[i][j]==1){
                    si = i;
                    sj = j;
                }
            }
        }
        
        free = n*m-obstacles;
        
        int ans = 0;
        int cov = 0;
        
        solve(grid, si, sj, ans, cov);
        
        return ans;
    }
};