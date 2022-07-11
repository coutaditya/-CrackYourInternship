// REMEMBER: m-coloring is a backtracking problem
// We pick one node and check if a colour is available by checking colors of all its neighbours

bool solve(bool graph[101][101], int m, int n, int node, vector<int> &color){
    if(node==n){
        return true;
    }
    
    for(int i=0; i<m; i++){
        bool avail = true;
        for(int j=0; j<n; j++){
            if(graph[node][j] && color[j]==i){
                avail = false;
                break;
            }
        }
        
        if(avail){
            color[node] = i;
            if(solve(graph, m, n, node+1, color)){
                return true;
            }
            color[node] = -1;
        }
    }
    
    return false;
    
}

bool graphColoring(bool graph[101][101], int m, int n) {
    
    vector<int> color(n, -1);
    return solve(graph, m, n, 0, color);
}