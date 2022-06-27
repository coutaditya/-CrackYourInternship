// Simple bfs solution
// TC: O(n) SC: O(n)

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int> > adj(n);
        queue<pair<int, int> > q;
        
        for(int i=0; i<n; i++){
            if(manager[i]==-1){
                q.push({i, 0});
            }
            else{
                adj[manager[i]].push_back(i);
            }
        }
        
        int ans = 0;
        while(!q.empty()){
            int node = q.front().first;
            int time = q.front().second;
            ans = max(ans, time);
            
            q.pop();
            
            for(auto i:adj[node]){
                q.push({i, time+informTime[node]});
            }
        }
        
        return ans;
    }
};