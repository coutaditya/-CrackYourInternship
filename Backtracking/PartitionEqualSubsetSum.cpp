// IDK why is this put in backtracking, this is the equal sum partition problem from DP

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i=0; i<N; i++){
            sum+=arr[i];
        }
        
        if(sum%2) return 0;
        
        sum/=2;
        vector<bool> prev(sum+1, false), cur(sum+1, false);
        prev[0] = true;
        
        for(int i=1; i<N+1; i++){
            cur[0] = true;
            for(int j=1; j<sum+1; j++){
                if(j>=arr[i-1]){
                    cur[j] = prev[j-arr[i-1]] || prev[j];
                }
                else cur[j] = prev[j];
            }
            prev = cur;
        }
        
        return prev[sum];
    }
};