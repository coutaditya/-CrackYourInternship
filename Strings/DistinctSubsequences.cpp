// Well, a dynamic programming problem. 
// Let us first define its state dp[i][j] to be the number of distinct subsequences of t[0..i - 1] in s[0..j - 1]. 
// Then we have the following state equations:

// 	General case 1: dp[i][j] = dp[i][j - 1] if t[i - 1] != s[j - 1];
// 	General case 2: dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1] if t[i - 1] == s[j - 1];
// 	Boundary case 1: dp[0][j] = 1 for all j;
// 	Boundary case 2: dp[i][0] = 0 for all positive i.
// Now let us give brief explanations to the four equations above.

// If t[i - 1] != s[j - 1], the distinct subsequences will not include s[j - 1] and thus all the number of distinct subsequences will simply be those in s[0..j - 2], which corresponds to dp[i][j - 1];
// If t[i - 1] == s[j - 1], the number of distinct subsequences include two parts: those with s[j - 1] and those without;
// An empty string will have exactly one subsequence in any string :-)
// Non-empty string will have no subsequences in an empty string.
// Putting these together, we will have the following simple codes (just like translation :-)):

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        
        vector<vector<long long> > dp(n+1, vector<long long>(m+1, 0));
        
        for(int i=0; i<n; i++) dp[i][0] = 1;
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = (dp[i-1][j-1]+dp[i-1][j])%(long long)(1e18+7);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][m];
    }
};


// A Space Optimised (1D DP Table) answer also exists: https://leetcode.com/problems/distinct-subsequences/discuss/37316/7-10-lines-C%2B%2B-Solutions-with-Detailed-Explanations-(O(m*n)-time-and-O(m)-space)