// DFS Implementation of topo sort
// It works only when it is known that graph is DAG
// It will give an answer in case of a cyclic graph as well, so watch out (you can always use that indegree wala method using queue, if that gives order.length < number of nodes, then cycle exists)

class Solution
{
    void dfs(int node, vector<int> adj[], vector<bool> &vis, vector<int> &order){
        vis[node] = true;
        for(auto i:adj[node]){
            if(!vis[i]){
                dfs(i, adj, vis, order);
            }
        }
        order.push_back(node);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> order;
	    vector<bool> vis(V, false);
	    for(int i=0; i<V; i++){
	        if(!vis[i])
	            dfs(0, adj, vis, order);
	    }
	    
	    
	    reverse(order.begin(), order.end());
	    return order;
	}
};