int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

class Solution {
public:
    void dfs(vector<vector<char> > &grid, int i, int j){
        int n = grid.size();
        int m = grid[0].size();
        grid[i][j] = '0';
        for(int k=0; k<4; k++){
            int xx = i+dx[k];
            int yy = j+dy[k];
            
            if(xx<n && xx>=0 && yy<m && yy>=0 && grid[xx][yy]=='1'){
                dfs(grid, xx, yy);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        
        return count;
    }
};