// Multisource bfs

class Solution 
{
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, int> > q;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        
        int ans = -1;
        
        while(!q.empty()){
            int s = q.size();
            ans++;
            for(int i=0; i<s; i++){
                int x = q.front().first;
                int y = q.front().second;
                
                q.pop();
                
                for(int k = 0; k<4; k++){
                    int xx = x+dx[k];
                    int yy = y+dy[k];
                    
                    if(xx<n && xx>=0 && yy<m && yy>=0 && grid[xx][yy]==1){
                        grid[xx][yy]=2;
                        q.push({xx, yy});
                    }
                }
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        
        return ans;
    }
};