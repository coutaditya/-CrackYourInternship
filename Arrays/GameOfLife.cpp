// We use 2 to denote an alive cell that is dead in the next state and 3 to denote a dead cell that becomes alive
// TC: O(n*m) SC: O(1)

int dx[8] = {1,1,1,0,0,-1,-1,-1};
int dy[8] = {-1,1,0,1,-1,1,-1,0};

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int alive = 0;
                for(int k=0; k<8; k++){
                    int xx = i+dx[k];
                    int yy = j+dy[k];

                    if(xx<n && xx>=0 && yy<m && yy>=0){
                        if(board[xx][yy]==1 || board[xx][yy]==2){
                            alive++;
                        }
                    }
                }
                if(board[i][j]==1){
                    if(alive<2 || alive>3){
                        board[i][j]=2;
                    }
                }
                else{
                    if(alive==3){
                        board[i][j]=3;
                    }
                }
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==2){
                    board[i][j]=0;
                }
                if(board[i][j]==3){
                    board[i][j]=1;
                }
            }
        }
    }
};