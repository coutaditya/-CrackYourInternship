class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int> > m;
        
        for(auto i:adjacentPairs){
            m[i[0]].push_back(i[1]);
            m[i[1]].push_back(i[0]);
        }
        
        vector<int> ans;
        for(auto i:m){
            if(i.second.size()==1){
                ans.push_back(i.first);
                break;
            }
        }
        
        int prev = ans[0];
        int cur = m[ans[0]][0];
        
        while(true){
            ans.push_back(cur);
            if(m[cur].size()==1){
                return ans;
            }
            else{
                if(m[cur][0]!=prev){
                    prev = cur;
                    cur = m[cur][0];
                }
                else{
                    prev = cur;
                    cur = m[cur][1];
                }
            }
        }
        
        return ans;
    }
};