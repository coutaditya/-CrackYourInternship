// Similar to house robber problem

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> m;
        vector<int> v;
        for(auto i:nums){
            if(m[i]==0){
                v.push_back(i);
            }
            m[i]++;
        }
        
        sort(v.begin(), v.end());
        
        vector<vector<int> > t(2, vector<int>(v.size(), 0));
        
        t[0][0] = m[v[0]]*v[0];
        t[1][0] = 0;
        
        for(int i=1; i<v.size(); i++){
            if(v[i]-v[i-1]==1){
                t[0][i] = t[1][i-1]+m[v[i]]*v[i];
            }
            else{
                t[0][i] = max(t[0][i-1], t[1][i-1])+m[v[i]]*v[i];
            }
            t[1][i] = max(t[0][i-1], t[1][i-1]);
        }
        
        return max(t[0][v.size()-1], t[1][v.size()-1]);
    }
};