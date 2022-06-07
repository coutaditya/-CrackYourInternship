// Standard Binary Search on Answer Problem (see BS notes)

class Solution 
{
    public:
    bool check(int A[], int N, int M, int x){
        int students = 1;
        int sum = 0;
        
        for(int i = 0; i<N; i++){
            sum+=A[i];
            if(sum>x){
                sum=A[i];
                students++;
            }
        }
        
        if(students>M) return false;
        
        return true;
    }
    
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        if(M>N) return -1;
        int mx = INT_MIN;
        int sum = 0;
        int ans = -1;
        
        for(int i=0; i<N; i++){
            sum+=A[i];
            mx = max(mx, A[i]);
        }
        
        int s = mx, e = sum;
        while(s<=e){
            int mid = s+(e-s)/2;
            // cout<<mid<<"\n";
            
            if(check(A, N, M, mid)){
                ans = mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        
        return ans;
    }
};