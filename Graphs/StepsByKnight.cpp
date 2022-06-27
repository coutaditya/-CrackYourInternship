// Start a bfs from knightPos to all valid cells

class Solution {
    int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
    int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};

    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N){
	    if(TargetPos[0]==KnightPos[0] && TargetPos[1]==KnightPos[1]) return 0;
	    
	    int steps = 0;
	    queue<pair<int, int> > q;
	    q.push({KnightPos[0], KnightPos[1]});
	    vector<vector<bool> > vis(N+1, vector<bool>(N+1, false));
	    vis[KnightPos[0]][KnightPos[1]] = true;
	    while(!q.empty()){
	        int n = q.size();
	        for(int j = 0; j<n; j++){
	            int x = q.front().first;
    	        int y = q.front().second;
    	        q.pop();
    	        for(int i=0; i<8; i++){
    	            int xx = x+dx[i];
    	            int yy = y+dy[i];
    	            
    	            if(xx==TargetPos[0] && yy==TargetPos[1]){
    	                return steps+1;
    	            }
    	            if(xx>0 && xx<=N && yy>0 && yy<=N && !vis[xx][yy]){
    	                vis[xx][yy] = true;
    	                q.push({xx, yy});
    	            }
    	        }
	        }
	        steps++;
	    }
	    return steps;
	}
};