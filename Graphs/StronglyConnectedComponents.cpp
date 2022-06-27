// Kosaraju's algorithm: see Graph Theory Notes
// Very simple and standard

class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int node, vector<int> adj[], vector<bool> &vis, vector<int> &order){
	    vis[node] = true;
	    
	    for(auto i:adj[node]){
	        if(!vis[i]) dfs(i, adj, vis, order);
	    }
	    
	    order.push_back(node);
	}
	
	void dfs2(int node, vector<int> adj[], vector<bool> &vis){
	    vis[node] = true;
	    
	    for(auto i:adj[node]){
	        if(!vis[i]) dfs2(i, adj, vis);
	    }
	}
	
    int kosaraju(int V, vector<int> adj[])
    {
        vector<int> radj [V];
        
        for(int i=0; i<V; i++){
            for(auto j:adj[i]){
                radj[j].push_back(i);
            }
        }
        
        vector<int> order;
        vector<bool> vis(V, false);
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, adj, vis, order);
            }
        }
        
        reverse(order.begin(), order.end());
        
        for(int i=0; i<V; i++){
            vis[i] = false;
        }
        int ans =0;
        for(auto i:order){
            if(!vis[i]){
                ans++;
                dfs2(i, radj, vis);
            }
        }
        
        return ans;
    }
};