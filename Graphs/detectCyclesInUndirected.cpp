class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool cycle(vector<int> adj[], int node, int par, vector<bool> &vis){
        vis[node] = true;
        for(auto i:adj[node]){
            if(i!=par && !vis[i]){
                if(cycle(adj, i, node, vis)){
                    return true;
                }
            }
            else if(i!=par && vis[i]){
                return true;
            }
        }
        return false;
        
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool>vis(V, false);
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(cycle(adj, i, -1, vis)){
                    return true;
                }
            }
        }
        return false;
    }
};