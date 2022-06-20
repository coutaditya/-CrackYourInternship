// Kruskals algo (kind of) but no need of sorting as the graph is undirected

class Solution {
public:
    int findSet(int u, vector<int> &par){
        if(par[u]==-1){
            return u;
        }
        
        return par[u] = findSet(par[u], par);
    }
    
    void Union(int i, int j, vector<int> &rank, vector<int> &par){
        int u = findSet(i, par);
        int v = findSet(j, par);
        
        if(rank[u]<rank[v]) swap(u,v);
        
        if(u!=v){
            rank[u]+=rank[v];
            par[v] = u;
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        vector<int> par(n+1, -1);
        vector<int> rank(n+1, 1);
        
        for(int i=0; i<n; i++){
            if(findSet(edges[i][0], par)==findSet(edges[i][1], par)){
                return edges[i];
            }
            else{
                Union(edges[i][0], edges[i][1], rank, par);
            }
        }
        
        return edges[n-1];
    }
};