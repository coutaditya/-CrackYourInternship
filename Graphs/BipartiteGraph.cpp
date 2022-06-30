// DOUBT (maybe stupid) why do we need the par in the dfs call?

bool dfs(int node, vector<vector<int> > graph, bool vis[], bool color[], int par){
    vis[node]=true;
    for(auto i:graph[node]){
        if(!vis[i]){
            color[i]=!color[node];
            if(!dfs(i, graph, vis, color, node)){
                return false;
            }
        }
        if(i!=par){
            if(color[i]==color[node]){
                return false;
            }
        }
        
    }
    return true;
}

bool isBipartite(vector<vector<int>> graph){
    int n=graph.size();
    bool vis[n]={false};
    bool color[n]={0};

    for(int i=0; i<n; i++){
        if(!vis[i]){
            if(!dfs(i, graph, vis, color, -1)){
                return false;
            }
        }
    }
    return true;
}