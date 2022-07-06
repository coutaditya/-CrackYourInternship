const int MOD = 1e9+7;
vector<vector<vector<int> > > t(5001, vector<vector<int> >(4, vector<int>(3, -1)));

class Solution {
    int dx[8] = {1,1,2,2,-1,-1,-2,-2};
    int dy[8] = {2,-2,1,-1,2,-2,1,-1};
    
    vector<vector<int> > mat = {{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
public:
    int solve(int i, int j, int n){
        if(n==1) return 1;
        
        if(t[n][i][j]!=-1) return t[n][i][j];
        
        long long ans = 0;
        for(int x=0; x<8; x++){
            int xx = i+dx[x];
            int yy = j+dy[x];
            if(xx<4 && xx>=0 && yy<3 && yy>=0 && mat[xx][yy]!=-1){
                ans+=solve(xx, yy, n-1);
                ans%=MOD;
            }
        }
        
        return t[n][i][j] = ans%MOD;
    }
    
    int knightDialer(int n) {
        long ans = 0;
        for(int i=0; i<4; i++){
            for(int j=0; j<3; j++){
                if(mat[i][j]!=-1){
                    // cout<<solve(i, j, n, t)<<"\n";
                    ans+=solve(i, j, n);
                    ans%=MOD;
                }
            }
        }
        return ans;
    }
};