class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int m = amount;
        
        vector<vector<int> > t(n+1, vector<int>(m+1, 0));
        
        for(int i=0; i<n+1; i++){
            t[i][0] = 0;
        }
        for(int i=1; i<m+1; i++){
            t[0][i] = INT_MAX-1;
        }
        
        for(int i=1; i<n+1; i++){
            for(int j = 1; j<m+1; j++){
                if(coins[i-1]<=j){
                    t[i][j] = min(t[i-1][j], t[i][j-coins[i-1]]+1);
                }
                else t[i][j] = t[i-1][j];
            }
        }
        
        if(t[n][m]==INT_MAX || t[n][m]==INT_MAX-1) return -1;
        
        return t[n][m];
    }
};