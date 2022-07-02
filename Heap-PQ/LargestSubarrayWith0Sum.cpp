class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int, int> m;
        int sum=0;
        int ans=0;
        m[0]=0;
        for(int i=0; i<n; i++){
            sum+=A[i];
            if(m[sum]==0 && sum!=0){
                m[sum]=i+1;
                // cout<<"m["<<sum<<"]="<<m[sum]<<"\n";
            }
            else{
                ans=max(ans, i+1-m[sum]);
            }
        }
        return ans;
    }
};