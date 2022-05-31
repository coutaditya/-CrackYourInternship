// When we find the first unequal element while moving the two pointers, we need to check by leaving each of the unequal elements.
// So we will use a recursive function call

class Solution {
public:
    bool solve(string s, int l, int r, int count){
        if(count>1) return false;
        
        while(l<r && s[l]==s[r]){
            l++; r--;
        }
        
        if(l<r){
            count++;
            
            return solve(s, l+1, r, count) || solve(s, l, r-1, count);
        }
        
        return true;
    }
    
    bool validPalindrome(string s) {
        int n = s.length();
        
        return solve(s, 0, n-1, 0);
    }
};