// TC: Elog(V)  SC: O(V)

class Solution{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        vector<bool> vis(n, false);    // to denote which edges have been taken into the MST so far

    	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    	q.push({0, 0}); // {weight, node}
    
    	int ans=0;
    
    	while(!q.empty()){
    		int wt = q.top().first;
    		int node = q.top().second;
    		q.pop();
    
    		if(vis[node]){
    			continue;
    		}
    
    		ans+=wt;
    		vis[node] = true;
    
    		for(auto i:adj[node]){
    			if(!vis[i[0]]){
    				q.push({i[1], i[0]});
    			}
    		}
    	}
    
    	return ans;
    }
};