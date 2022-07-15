class Solution {
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    
    void dfs(int i, int j, vector<vector<int> > &grid, int c, int &count){
        count++;
        grid[i][j] = c;
        
        for(int x=0; x<4; x++){
            int xx = i+dx[x];
            int yy = j+dy[x];
            
            if(xx<grid.size() && xx>=0 && yy<grid[0].size() && yy>=0 && grid[xx][yy]==1){
                dfs(xx, yy, grid, c, count);
            }
        }
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 1;
        
        vector<int> sz;
        int c = 2;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    int count = 0;
                    dfs(i, j, grid, c, count);
                    ans = max(ans, count);
                    sz.push_back(count);
                    c++;
                }
            }
        }
        
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==0){
                    set<int> s;
                    for(int x=0; x<4; x++){
                        int x1 = i+dx[x], y1 = j+dy[x];
                        if(x1<n && x1>=0 && y1<m && y1>=0 && grid[x1][y1]!=0){
                            s.insert(grid[x1][y1]);
                        }
                    }
                    int res = 1;
                    for(auto i:s){
                        res+=(sz[i-2]);
                    }
                    
                    ans = max(ans, res);
                }
            }
        }
        
        return ans;
    }
};