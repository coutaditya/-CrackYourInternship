class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool cycle(vector<int> adj[], int node, vector<bool> &curCyc, vector<bool> &vis){
        vis[node] = true;
        curCyc[node] = true;
        
        for(auto i:adj[node]){
            if(!vis[i]){
                if(cycle(adj, i, curCyc, vis)){
                    return true;
                }
            }
            else if(curCyc[i]){
                return true;
            }
        }
        
        curCyc[node] = false;
        
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> curCyc(V, false);
        vector<bool> vis(V, false);
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(cycle(adj, i, curCyc, vis)){
                    return true;
                }
            }
        }
        
        return false;
    }
};