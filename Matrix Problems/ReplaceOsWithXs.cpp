// This is mainly an application of Flood-Fill algorithm. The main difference here is that a ‘O’ is not replaced by ‘X’ if it lies in region that ends on a boundary. Following are simple steps to do this special flood fill.
// 1) Traverse the given matrix and replace all ‘O’ with a special character ‘-‘.
// 2) Traverse four edges of given matrix and call floodFill(‘-‘, ‘O’) for every ‘-‘ on edges. The remaining ‘-‘ are the characters that indicate ‘O’s (in the original matrix) to be replaced by ‘X’.
// 3) Traverse the matrix and replace all ‘-‘s with ‘X’s. 


// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

// All the Os connected to a boundary won't change, so well call a dfs from boundary Os and make the unvisited Os as X
class Solution{
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    void dfs(vector<vector<char> >&mat, int i, int j, int n, int m){
        mat[i][j] = 'O';
        
        for(int k=0; k<4; k++){
            int x = i+dx[k];
            int y = j + dy[k];
            
            if(x<n && x>=0 && y<m && y>=0 && mat[x][y]=='-'){
                dfs(mat, x, y, n, m);
            }
        }
        
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]=='O'){
                    mat[i][j] = '-';
                }
            }
        }
        
        for(int i=0; i<n; i++){
            if(mat[i][0]=='-'){
                dfs(mat, i, 0, n, m);
            }
            if(mat[i][m-1]=='-'){
                dfs(mat, i, m-1, n, m);
            }
        }
        
        for(int i=0; i<m; i++){
            if(mat[0][i]=='-'){
                dfs(mat, 0, i, n, m);
            }
            if(mat[n-1][i]=='-'){
                dfs(mat, n-1, i, n, m);
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]=='-'){
                    mat[i][j] = 'X';
                }
            }
        }
        
        return mat;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends