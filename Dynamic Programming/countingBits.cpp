// write the binary representation of n numbers and observe the pattern

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        ans[0] = 0; 
        if(n==0) return ans;
        ans[1] = 1;
        
        int d = 0;
        for(int i=2; i<n+1; i++){
            if((i&(i-1))==0){
                // cout<<i<<" ";
                d = i;
            }
            
            ans[i] = 1+ans[i-d];
        }
        
        return ans;
    }
};