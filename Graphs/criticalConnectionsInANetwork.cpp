// Simple problem of finding the bridges in a graph

class Solution {
    int time;
    
    void dfs(int node, int par, vector<vector<int> > &adj, vector<bool> &vis, vector<int> &disc, vector<int> &low, vector<vector<int> > &ans){
        vis[node] = true;
        disc[node] = low[node] = time++;
        
        for(auto i:adj[node]){
            if(!vis[i]){
                dfs(i, node, adj, vis, disc, low, ans);
                
                low[node] = min(low[node], low[i]);
                
                // Bridge detected
                if(low[i]>disc[node]){
                    ans.push_back({i, node});
                }
            }
            else if(i!=par){
                low[node] = min(disc[i], low[node]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int> > adj(n);
        time = 0;
        
        for(auto i:connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        vector<int> disc(n, 0), low(n, 0);
        
        vector<bool> vis(n, false);
        vector<vector<int> > ans;
        
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(0, -1, adj, vis, disc, low, ans);
            }
        }
        
        return ans;
    }
};