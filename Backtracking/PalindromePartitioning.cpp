class Solution {
public:
    bool isPalindrome(string s){
        int i=0, j = s.length()-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            
            i++;
            j--;
        }
        
        return true;
    }
    
    void solve(vector<vector<string> > &ans, vector<string> &t, string s, int i){
        if(i==s.length()){
            ans.push_back(t);
        }
        
        for(int j=i; j<s.length(); j++){
            if(isPalindrome(s.substr(i, j-i+1))){
                t.push_back(s.substr(i, j-i+1));
                solve(ans, t, s, j+1);
                t.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ans;
        vector<string> t;
        
        solve(ans, t, s, 0);
        
        return ans;
    }
};