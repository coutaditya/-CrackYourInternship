class Solution{
  public:
    bool solve(int a[], int sum, int cur, int k, int n, int &cov){
        if(k==0){
            if(cov==n) return true;
            else return false;
        }
        
        for(int j=0; j<n; j++){
            if(a[j]!=-1){
                if(cur+a[j]<sum){
                    cov++;
                    cur+=a[j];
                    int t = a[j];
                    a[j]=-1;
                    if(solve(a, sum, cur, k, n, cov)) return true;
                    a[j]=t;
                    cur-=a[j];
                    cov--;
                }
                else if(cur+a[j]==sum){
                    cov++;
                    int t = a[j];
                    a[j]=-1;
                    if(solve(a, sum, 0, k-1, n, cov)) return true;
                    a[j]=t;
                    cov--;
                }
            }
        }
        
        return false;
    }
  
    bool isKPartitionPossible(int a[], int n, int k)
    {
         //Your code here
         int l = INT_MAX, r = 0;
         for(int i=0; i<n; i++){
             l = min(l, a[i]);
             r+=a[i];
         }
         
         if(k==1) return true;
         if(k>n) return false;
         if(r%k!=0) return false;
         
         r/=k;
         int cov = 0;
         
         for(int i=l; i<=r; i++){
             if(solve(a, i, 0, k, n, cov)) return true;
         }
         
         return false;
    }
};