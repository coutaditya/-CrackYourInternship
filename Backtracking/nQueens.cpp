class Solution {
public:
    bool isallowed(vector<string> &board, int i, int j, int n){
        for(int x = 0; x<n; x++){
            if(board[i][x]=='Q') return false;
            if(board[x][j]=='Q') return false;
        }
        int t1 = j+1;
        int t2 = i-1;
        while(t2>=0 && t1<n){
            if(board[t2][t1]=='Q') return false;
            
            t2--;
            t1++;
        }
        
        t1 = j-1;
        t2 = i-1;
        while(t2>=0 && t1>=0){
            if(board[t2][t1]=='Q') return false;
            
            t2--;
            t1--;
        }
        
        return true;
    }
    
    void solve(vector<vector<string> > &ans, int i, int n, vector<string> &board){
        if(i==n){
            ans.push_back(board);
            return;
        }
        
        for(int j=0; j<n; j++){
            if(isallowed(board, i, j, n)){
                board[i][j] = 'Q';
                solve(ans, i+1, n, board);
                board[i][j] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> > ans;
        string s="";
        for(int i=0; i<n; i++){
            s.push_back('.');
        }
        vector<string> board (n, s);
        
        solve(ans, 0, n, board);
        
        return ans;
    }
    
};