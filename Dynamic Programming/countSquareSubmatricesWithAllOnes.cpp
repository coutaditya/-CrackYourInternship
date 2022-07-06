// My 'ghisa-pita' O(n*m*min(n, m)) code

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m  =matrix[0].size();
        
        int sz = 1;
        while(sz<=(min(n, m))){
            
            for(int i=sz; i<n; i++){
                for(int j=sz; j<m; j++){
                    if(matrix[i][j]==sz && matrix[i][j]<=matrix[i-1][j] && matrix[i][j]<=matrix[i-1][j-1] && matrix[i][j]<=matrix[i][j-1]){
                        matrix[i][j]++;
                    }
                }
            }
            sz++;
        }
        
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j = 0; j<m; j++){
                ans+=matrix[i][j];
            }
        }
        
        return ans;
        
        
    }
};


// O(n*m) optimised DP

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m  =matrix[0].size();
        
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                int val = min(matrix[i-1][j], matrix[i][j-1]);
                val = min(val, matrix[i-1][j-1]);
                if(matrix[i][j]) matrix[i][j]+=val;
            }
        }
        
        int ans = 0;
        
        for(auto i:matrix){
            for(auto j:i){
                
                ans+=j;
            }
            
        }
        
        return ans;
        
        
    }
};