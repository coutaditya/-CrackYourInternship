// Sliding Window Code
//  TC: O(26*n) SC: O(1)

class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        int n = s.length();
        for(char c='A'; c<='Z'; c++){
            int start = 0, end = 0, other = 0;
            while(end<n){
                if(s[end]!=c){
                    other++;
                }
                
                if(other>k){
                    if(s[start]!=c){
                        other--;
                    }
                    start++;
                }
                
                ans = max(ans, (end-start+1));
                end++;
            }
        }
        
        return ans;
    }
};