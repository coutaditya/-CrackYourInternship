class Solution {
public:
    void solve(int &ans, int i, int n, vector<bool> &avail){
        if(i==n+1){
            ans++;
            return;
        }
        
        for(int j=1; j<n+1; j++){
            if((j%i==0 || i%j==0) && avail[j]){
                avail[j] = false;
                solve(ans, i+1, n, avail);
                avail[j] = true;
            }
        }

    }
    
    int countArrangement(int n) {
        int ans = 0;
        vector<bool> avail(n+1, true);
        solve(ans, 1, n, avail);
        
        return ans;
    }
};