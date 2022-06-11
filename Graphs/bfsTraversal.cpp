class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        queue<int> q;
        vector<bool> vis(V, false);
        vector<int> ans;
        q.push(0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            vis[node]=true;
            for(auto i:adj[node]){
                if(!vis[i]){
                    vis[i] = true;
                    q.push(i);
                }
            }
        }
        
        return ans;
    }
};