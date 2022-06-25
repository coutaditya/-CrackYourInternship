// https://www.youtube.com/watch?v=gmEsErNo84g&ab_channel=CodingDecoded
// Also, see SDE Sheet Problem Notes. Very very interesting logic.

class Solution {
    vector<int> dist;
    vector<int> sub;
public:
    void dfs(int node, vector<vector<int> > &adj, vector<bool> &vis){
        vis[node] = true;
        
        for(auto i:adj[node]){
            if(!vis[i]){
                dfs(i, adj, vis);
                sub[node]+=sub[i];
                dist[node]+= (sub[i]+dist[i]);
            }
        }
    }
    
    void solve(int node, vector<vector<int> > &adj, vector<bool> &vis){
        vis[node] = true;
        
        for(auto i:adj[node]){
            if(!vis[i]){
                dist[i] = dist[node]-(sub[i])+(adj.size()-sub[i]);
                solve(i, adj, vis);
            }
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        dist.resize(n, 0);
        sub.resize(n, 1);
        vector<bool> vis(n, false);
        
        vector<vector<int> > adj(n);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        dfs(0, adj, vis);
        
        for(int i=0; i<n; i++){
            vis[i] = false;
        }
        
        solve(0, adj, vis);
        
        return dist;
    }
};