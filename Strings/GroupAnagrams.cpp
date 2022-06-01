// We use unordered_map and counting sort to do the grouping. Please appreciate this beautiful algorithm

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string> > m;
        
        for(auto s: strs){
            // For each anagram, the sorted string will be the same hence they will be stored in the same key in the map
            m[Sort(s)].push_back(s);   
        }
        
        vector<vector<string> > ans;
        for(auto i:m){
            ans.push_back(i.second);
        }
        
        return ans;
    }
    
    // Since Questions states that we only have lower case characters, we will use counting sort to sort the array in linear time
    string Sort(string s){
        int count[26] = {0};
        
        for(auto i:s){
            count[i-'a']++;
        }
        
        string ans = "";
        
        for(int i=0; i<26; i++){
            for(int j=0; j<count[i]; j++){
                ans.push_back(char(i+'a'));
            }
        }
        
        return ans;
    }
};