// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int MAH(int A[], int m){
        vector<int> NSL(m, 0);
        vector<int> NSR(m, 0);
        
        stack<int> s;
        
        for(int i=m; i>=0; i--){
            
            while(!s.empty() && A[s.top()]>=A[i]){
                s.pop();
            }
            if(s.empty()){
                NSR[i] = m;
            }
            else{
                NSR[i] = s.top();
            }
            
            s.push(i);
        }
        
        while(!s.empty()){
            s.pop();
        }
        
        for(int i=0; i<m; i++){
            
            while(!s.empty() && A[s.top()]>=A[i]){
                s.pop();
            }
            if(s.empty()){
                NSL[i] = -1;
            }
            else{
                NSL[i] = s.top();
            }
            
            s.push(i);
        }
        
        
        long long ans = 0;
        for(int i=0; i<m; i++){
            ans = max(ans, (long long)A[i]*(NSR[i]-NSL[i]-1));
        }
        
        return ans;
    }
  
    int maxArea(int M[MAX][MAX], int n, int m) {
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                if(M[i][j]!=0){
                    M[i][j]=M[i-1][j]+1;
                }
            }
        }
        
        int ans = 0;
        for(int i=0; i<n; i++){
            ans = max(ans, MAH(M[i], m));
        }
        
        return ans;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends