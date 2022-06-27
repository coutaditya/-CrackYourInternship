// Standard DSU Problem

class Solution {
    vector<int> Rank;
    vector<int> Par;
public:
    int findSet(int u){
        if(Par[u]==-1) return u;
        
        return Par[u] = findSet(Par[u]);
    }
    
    void unionSet(int u, int v){
        int p = findSet(u);
        int q = findSet(v);
        
        if(Rank[p]<Rank[q]) swap(p, q);
        
        Par[q] = p;
        Rank[p]+=Rank[q];
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        Rank.resize(n, 1);
        Par.resize(n, -1);
        
        int extra_cables = 0, comp = 0;
        for(auto i:connections){
            if(findSet(i[0])==findSet(i[1])){
                extra_cables++;
            }
            else{
                unionSet(i[0], i[1]);
            }
        }
        
        for(auto i:Par){
            if(i==-1){
                comp++;
            }
        }
        
        if(extra_cables<(comp-1)){
            return -1;
        }
        else{
            return (comp-1);
        }
    }
};