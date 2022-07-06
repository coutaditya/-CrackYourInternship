// Space optimised tabulation

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> t(n, 1);
        
        for(int i = 1; i < m; i++){
            vector<int> cur(n, 0);
            cur[0] = 1;
            for(int j = 1; j<n; j++){
                cur[j] = cur[j-1]+t[j];
            }
            
            t = cur;
        }
        
        return t[n-1];
    }
};