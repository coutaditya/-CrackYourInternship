class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& list) {
        map<string, vector<string> > m;
        for(int i=0; i<list.size(); i++){
            string s = list[i];
            sort(s.begin(), s.end());
            m[s].push_back(list[i]);
        }
        
        vector<vector<string> > ans;
        for(auto it=m.begin(); it!=m.end(); it++){
            vector<string> v = it->second;
            // sort(v.begin(), v.end());
            ans.push_back(v);
        }
        
        return ans;
    }
};