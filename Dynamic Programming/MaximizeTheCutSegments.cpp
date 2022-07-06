class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> size = {x, y, z};
        vector<vector<int> > t(4, vector<int>(n+1, 0));
        
        // The last cut was not of one of the given sizes
        for(int i=1; i<n+1; i++){
            t[0][i] = -1e5;
        }
        
        for(int i=0; i<4; i++){
            t[i][0] = 0;
        }
        
        // t[0][0] = 0;
        
        
        
        for(int i=1; i<4; i++){
            for(int j = 1; j<n+1; j++){
                if(size[i-1]<=j){
                    t[i][j] = max(t[i-1][j], t[i][j-size[i-1]]+1);
                }
                // else if(size[i-1]==j){
                //     t[i][j] = max(t[i-1][j], t[i][j-size[i-1]]);
                // }
                else t[i][j] = t[i-1][j];
            }
        }
        
        if(t[3][n]<0) return 0;
        
        return t[3][n];
    }
};