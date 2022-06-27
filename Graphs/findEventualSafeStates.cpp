// Basically we need to find the nodes that do not lie in any cycle 
// EXPLANATION: https://www.youtube.com/watch?v=Re_v0j0CRsg&ab_channel=NeetCode
// TC: O(n) SC: O(n)

class Solution {
public:
    bool dfs(int node, vector<vector<int> > &graph, vector<int> &status){
        status[node] = 1;
        
        for(auto i:graph[node]){
            if(status[i]==0){
                if(!dfs(i, graph, status)){
                    return false;
                }
            }
            if(status[i]==1){
                return false;
            }
        }
        
        status[node] = 2;
        return true;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> status(n, 0);  // 0=>unvisited, 1=>visited and unsafe, 2=>visited and safe
        
        for(int i = 0; i<n; i++){
            if(status[i]==0){
                dfs(i, graph, status);
            }
        }
        
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(status[i]==2){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};