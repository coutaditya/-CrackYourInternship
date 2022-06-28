// Make a graph where an edge exists between 2 points, if they have a same row or column
// The answer is the number of total nodes - number of components

class Solution {
public:
    void dfs(int node, vector<vector<int> > &adj, vector<bool> &vis){
        vis[node] = true;
        
        for(auto i:adj[node]){
            if(!vis[i]){
                dfs(i, adj, vis);
            }
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int> > adj(n);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<bool> vis(n, false);
        int comp = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i, adj, vis);
                comp++;
            }
        }
        
        return n-comp;
    }
};

// APPROACH 2: We can also use union-find to solve this