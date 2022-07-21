class Solution {
public:
    bool allowed(vector<vector<char> > &board, int i, int j, int k){
       for(int x=0; x<9; x++){
            if((board[i][x]-'0')==k){
                return false;
            }
            if((board[x][j]-'0')==k){
                return false;
            }
        }
        
        int xx = (i/3)*3;
        int yy = (j/3)*3;
        
        for(int x=xx; x<xx+3; x++){
            for(int y=yy; y<yy+3; y++){
                if((board[x][y]-'0')==k){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool solve(vector<vector<char> > &board, int i, int j){
        if(i==9) return true;
        
        if(j==9) return solve(board, i+1, 0);
        
        if(board[i][j]!='.'){
            return solve(board, i, j+1);
        }
        
        for(int k=1; k<=9; k++){
            if(allowed(board, i, j, k)){
                board[i][j] = char(k+'0');
                if(solve(board, i, j+1)){
                    return true;
                }
                board[i][j] = '.';
            }
        }
        
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};