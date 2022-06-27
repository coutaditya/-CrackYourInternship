class Solution {
public:
    string solve(string &s, int &i){
        string ans = "";
        while(i<s.length() && s[i]!=']'){
            if(!isdigit(s[i])){
                ans+=s[i];
                i++;
            }
            else{
                int j = i;
                while(i<s.length() && isdigit(s[i])){
                    i++;
                }
                
                int n = stoi(s.substr(j, i-j));
                
                i++;  // skip the [
                string t = solve(s, i);
                i++; // skip the ]
                
                for(int k=0; k<n; k++){
                    ans+=t;
                }
            }
        }
        
        return ans;
    }
    
    string decodeString(string s) {
        int i = 0;
        return solve(s, i);
    }
};