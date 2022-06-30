// DFS based interesting solution explanation: https://leetcode.com/problems/evaluate-division/discuss/171649/1ms-DFS-with-Explanations

class Solution {
public:
    double dfs(string start, string end, unordered_map<string, unordered_map<string, double> >&m, unordered_set<string> &vis){
        if(m.find(start)==m.end()) return -1;  // start does not exist in the list of numerators, denominators
        
        if(m[start].find(end)!=m[start].end()){
            return m[start][end];
        }
        
        for(auto i:m[start]){
            if(find(vis.begin(), vis.end(), i.first)!=vis.end()){
                continue;
            }
            vis.insert(i.first);
            
            if(dfs(i.first, end, m, vis)!=-1){
                return m[start][end] = m[start][i.first]*m[i.first][end];
            }
        }
        
        return -1;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double> > m;
        
        int n = equations.size();
        
        for(int i=0; i<n; i++){
            string a = equations[i][0];
            string b = equations[i][1];
            
            m[a][a] = 1.0;
            m[b][b] = 1.0;
            m[a][b] = values[i];
            m[b][a] = 1.0/values[i];
        }
        
        vector<double> ans;
        for(auto i:queries){
            unordered_set<string> vis;
            vis.insert(i[0]);
            ans.push_back(dfs(i[0], i[1], m, vis));
        }
        
        return ans;
    }
};