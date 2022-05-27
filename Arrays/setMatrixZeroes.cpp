// Rather than storing the rows and columns in a set, we will use the last row and column to keep track of
// rows and columns that have to be zeroed(dunno if that is a word)
// First we will check if originally the last row and column have a zero, then we will have to make all values zero for the last row/column at the end

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        // set<int> rows;
        // set<int> columns;
        bool lr=false, lc=false;
        for(int i=0; i<n; i++){
            if(matrix[i][m-1]==0){
                lr=true;
            }
        }
        for(int j=0; j<m; j++){
            if(matrix[n-1][j]==0){
                lc=true;
            }
        }
        
        for(int i=0; i<n-1; i++){
            for(int j=0; j<m-1; j++){
                if(matrix[i][j]==0){
                    matrix[i][m-1]=0;
                    matrix[n-1][j]=0;
                }
            }
        }
        
        for(int i=0; i<n-1; i++){
            if(matrix[i][m-1]==0){
                for(int t=0; t<m; t++){
                    matrix[i][t]=0;
                }
            }
        }
        for(int j=0; j<m-1; j++){
            if(matrix[n-1][j]==0){
                for(int t=0; t<n; t++){
                    matrix[t][j]=0;
                }
            }
        }
        
        if(lr){
            for(int i=0; i<n; i++){
                matrix[i][m-1]=0;
            }
        }
        if(lc){
            for(int j=0; j<m; j++){
                matrix[n-1][j]=0;
            }
        }
    }
};