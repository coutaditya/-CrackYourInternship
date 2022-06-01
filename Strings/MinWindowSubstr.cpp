// Standard Variable sized Sliding Window Problem (see notes)

class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size()) return "";
        
        unordered_map<char, int> m;
        unordered_set<char> S;
        
        for(auto str:t){
            m[str]++;
            S.insert(str);
        }
        
        int count = S.size();
        
        int i = 0, j = 0;
        int n = s.length();
        int idx = -1, size = INT_MAX;
        while(j<n){
            if(count>0){
                if(S.count(s[j])){
                    m[s[j]]--;
                    if(m[s[j]]==0){
                        count--;
                    }
                }
                j++;
            }
            else{
                if(size>(j-i)){
                    idx = i;
                    size = j-i;
                }
                
                if(S.count(s[i])){
                    m[s[i]]++;
                    if(m[s[i]]==1){
                        count++;
                    }
                }
                i++;
            }
        }
        while(i<n && count==0){
            if(size>(j-i)){
                idx = i;
                size = j-i;
            }

            if(S.count(s[i])){
                m[s[i]]++;
                if(m[s[i]]==1){
                    count++;
                }
            }
            i++;
        }
        
        if(idx == -1) return "";
        
        return s.substr(idx, size);
    }
};