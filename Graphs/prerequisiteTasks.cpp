// If a cycle exists in the directed graph, the execution of tasks is not possible, else it is
// Hence, this is a cycle detection in directed graph problem

class Solution {
public:
    bool isCyclic(int node, vector<vector<int> > &adj, vector<bool> &vis, vector<bool> &cur){
        vis[node] = true;
        cur[node] = true;
        for(auto i:adj[node]){
            if(!vis[i]){
                if(isCyclic(i, adj, vis, cur)){
                    return true;
                }
            }
            else if(cur[i]){
                return true;
            }
        }
        cur[node] = false;
        return false;
    }

	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    vector<vector<int> > adj(N);
	    
	    for(auto i:prerequisites){
	        adj[i.second].push_back(i.first);
	    }
	    
	    vector<bool> vis(N, false);
	    vector<bool> cur(N, false);
	    
	    for(int i=0; i<N; i++){
	        if(!vis[i] && isCyclic(i, adj, vis, cur)){
	            return false;
	        }
	    }
	    
	    return true;
	}
};