// Multisource bfs from all cells containing 1s

class Solution 
{
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,-1,1};
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    queue<pair<int, int> > q;
	    int n = grid.size();
	    int m = grid[0].size();
	    
	    vector<vector<int> > dist(n, vector<int>(m, INT_MAX));
	    
	    for(int i=0; i<n; i++){
	        for(int j=0; j<m; j++){
	            if(grid[i][j]==1){
	                dist[i][j]=0;
	                q.push({i,j});
	            }
	        }
	    }
	    
	    while(!q.empty()){
	        int x = q.front().first;
	        int y = q.front().second;
	        
	        q.pop();
	        
	        for(int k=0; k<4; k++){
	            int xx = x+dx[k];
	            int yy = y+dy[k];
	            
	            if(xx<n && xx>=0 && yy<m && yy>=0 && grid[xx][yy]==0 && (dist[xx][yy]>(dist[x][y]+1))){
	                dist[xx][yy] = dist[x][y]+1;
	                q.push({xx, yy});
	            }
	        }
	    }
	    
	    return dist;
	}
};