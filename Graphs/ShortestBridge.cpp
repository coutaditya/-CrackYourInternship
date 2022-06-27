// We start a bfs from the first island extending it by one cell each time till it touches the next island

class Solution {
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
public:
    void dfs(vector<vector<int> > &temp, int i, int j, int x){
        temp[i][j] = x;
        for(int k=0; k<4; k++){
            int xx = i+dx[k];
            int yy = j+dy[k];
            
            if(xx<temp.size() && xx>=0 && yy<temp.size() && yy>=0 && temp[xx][yy]== 1){
                dfs(temp, xx, yy, x);
            }
        }
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int> > temp = grid;
        
        int x = 2;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(temp[i][j]==1){
                    dfs(temp, i, j, x);
                    x++;
                }
            }
        }
        
        queue<pair<int, int> > q;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(temp[i][j]==2){
                    q.push({i, j});
                }
            }
        }
        
        int steps = 0;
        while(!q.empty()){
            int s = q.size();
            for(int i=0; i<s; i++){
                int x = q.front().first;
                int y = q.front().second;
                
                q.pop();
                for(int j=0; j<4; j++){
                    int xx = x+dx[j];
                    int yy = y+dy[j];

                    if(xx<temp.size() && xx>=0 && yy<temp.size() && yy>=0){
                        if(temp[xx][yy]==0){
                            temp[xx][yy]=1;
                            q.push({xx, yy});
                        }
                        else if(temp[xx][yy]==3){
                            return steps;
                        }
                    }
                }
                
            }
            steps++;
        }
        
        return steps;
    }
};