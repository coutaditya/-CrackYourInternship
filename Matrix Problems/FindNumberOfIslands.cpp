// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int dx[8] = {1,1,1,-1,-1,-1,0,0};
    int dy[8] = {0,-1,1,0,-1,1,1,-1};
  
    void dfs(vector<vector<char> > grid, vector<vector<bool> > &vis, int i, int j, int n, int m){
        vis[i][j] = true;
        for(int k=0; k<8; k++){
            int xx = i+dx[k];
            int yy = j+dy[k];
            
            if(xx>=0 && xx<n && yy>=0 && yy<m && grid[xx][yy]=='1' && !vis[xx][yy]){
                dfs(grid, vis, xx, yy, n, m);
            }
        }
    }
    
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool> > vis(n, vector<bool>(m, false));
    
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    count++;
                    dfs(grid, vis, i, j, n, m);
                }
            }
        }
    
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends