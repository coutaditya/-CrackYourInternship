// Simple Flood Fill Algorithm

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

class Solution {
public:
    bool wordSearch(vector<vector<char> > &board, vector<vector<bool> > &vis, string word, int i, int j, int k){
        // cout<<i<<" "<<j<<"\n";
        if(k==(word.length()-1)) return (word[k]==board[i][j]);
        
        int n = board.size();
        int m = board[0].size();
        
        if(board[i][j]!=word[k]){
            return false;
        }
        
        vis[i][j] = true;
        
        for(int x = 0; x<4; x++){
            int xx = i+dx[x];
            int yy = j+dy[x];
            
            if(xx<n && xx>=0 && yy<m && yy>=0 && !vis[xx][yy]){
                if(wordSearch(board, vis, word, xx, yy, k+1)){
                    return true;
                }
            }
        }
        
        vis[i][j] = false;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<bool> > vis(n, vector<bool>(m, false));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(wordSearch(board, vis, word, i, j, 0)){
                    return true;
                }
            }
        }
        
        return false;
    }
};