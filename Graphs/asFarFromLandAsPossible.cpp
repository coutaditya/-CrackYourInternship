// Multi-source BFS

class Solution {
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        
        queue<pair<int, int> > q;
        for(int i=0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]==1){
                    q.push({i, j});
                }
            }
        }
        if(q.size()==0 || q.size()==n*n) return -1;
        
        int ans = 0;
        
        while(!q.empty()){
            int s = q.size();
            for(int i=0; i<s; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                for(int j=0; j<4; j++){
                    int xx = x+dx[j];
                    int yy = y+dy[j];
                    
                    if(xx<n && xx>=0 && yy<n && yy>=0 && grid[xx][yy]==0){
                        grid[xx][yy] = 2;
                        q.push({xx, yy});
                    }
                }
            }
            ans++;
        }
        
        return ans-1;
    }
};