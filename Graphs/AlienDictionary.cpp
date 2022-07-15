// Create a directed graph based on letters of words and then do a topological sort

class Solution{
    void dfs(int node, vector<bool> &vis, vector<int> &order, vector<vector<int> > &adj){
            vis[node] = true;
            
            for(auto i:adj[node]){
                if(!vis[i]){
                    dfs(i, vis, order, adj);
                }
            }
            
            order.push_back(node);
    }
    
    public:
    string findOrder(string dict[], int N, int K) {
        vector<vector<int> > adj(K);
        
        for(int i=0; i<N-1; i++){
            string a = dict[i];
            string b = dict[i+1];
            
            int j=0;
            while(j<a.length() && j<b.length() && a[j]==b[j]){
                j++;
            }
            
            if(j<a.length() && j<b.length()){
                adj[a[j]-'a'].push_back(b[j]-'a');
            }
        }
        
        vector<bool> vis(N, false);
        vector<int> order;
        
        for(int i=0; i<K; i++){
            if(!vis[i]){
                dfs(i, vis, order, adj);
            }
        }
        
        reverse(order.begin(), order.end());
        
        string ans = "";
        
        for(auto i:order){
            ans.push_back(char(i+'a'));
        }
        
        return ans;
    }
};