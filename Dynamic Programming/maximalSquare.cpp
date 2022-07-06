// Similar to the prev problem: count sq submatrices with all ones
// O(n*m) solution

class Solution {
public:
    int maximalSquare(vector<vector<char>>& M) {
        int n = M.size();
        int m = M[0].size();
        
        vector<vector<int> > t(n, vector<int>(m, 0));
        int ans = 0;
        
        for(int i=0; i<n; i++){
            t[i][0] = M[i][0]-'0';
            if(t[i][0]) ans = 1;
        }
        
        for(int i=1; i<m; i++){
            t[0][i] = M[0][i]-'0';
            if(t[0][i]) ans = 1;
        }
        
        
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(M[i][j]!='0'){
                    t[i][j] = min(t[i-1][j], min(t[i-1][j-1], t[i][j-1]))+1;
                    ans = max(ans, t[i][j]);
                } 
            }
        }
        return ans*ans;
    }
};