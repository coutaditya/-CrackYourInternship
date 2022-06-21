// The number of structurally unique binary trees with n nodes = nth catalan number
// Catalan Number: https://www.geeksforgeeks.org/program-nth-catalan-number/

// nth Catalan Number = (1/(n+1))*(2nCn) (altho a recursive formula also exists, read article)

// TC:O(n^2) SC:O(n^2) solution using pascal traingle to cal nCr
class Solution {
public:
    long long nCr(int n, int r){
        vector<vector<long long> > pascal(n+1, vector<long long>(n+1, 1));
        for(int i=2; i<=n; i++){
            for(int j = 1; j<i; j++){
                pascal[i][j] = pascal[i-1][j]+pascal[i-1][j-1];
            }
        }
        
        return pascal[n][r];
    }
    
    int numTrees(int n) {
        return nCr(2*n, n)/(long long)(n+1);
    }
};

// TC:O(n) SC:O(1) solution cal nCr in linear time
class Solution {
public:
    long long nCr(int n, int r){
        long long ans = 1;
        long long t = 0;
        
        while(t!=r){
            t++;
            ans*=(n-t+1);
            ans/=t;
        }
        
        return ans;
    }
    
    int numTrees(int n) {
        return nCr(2*n, n)/(long long)(n+1);
    }
};