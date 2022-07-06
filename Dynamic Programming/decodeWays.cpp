// Memoized recursive solution

class Solution {
public:
    int solve(string s, int i, int n, vector<int> &t){
        if(i<n && s[i]=='0') return 0;
        
        if(i>=n) return 1;
        
        if(t[i]!=-1) return t[i];
        
        int ans = 0;
        
        if(s[i]!='0') ans += solve(s, i+1, n, t);
        
        if(i+1<n && ((s[i]=='1' && s[i+1]<='9') || (s[i]=='2' && s[i+1]<'7'))){
            ans+=solve(s, i+2, n, t);
        }
        
        return t[i] = ans;
    }
    
    int numDecodings(string s) {
        int n = s.length();
        
        vector<int> t(n+1, -1);
        return solve(s, 0, n, t);
    }
};

// Tabulation (faster than 100%)

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        
        vector<int> t(n+1, 0);
        t[n] = 1;
        for(int i=n-1; i>=0; i--){
            if(s[i]=='0'){
                t[i] = 0;
                continue;
            } 
            
            t[i]+=t[i+1];
            if(i+1<n && ((s[i]=='1' && s[i+1]<='9') || (s[i]=='2' && s[i+1]<'7'))){
                t[i]+=t[i+2];
            }
        }
        return t[0];
    }
};