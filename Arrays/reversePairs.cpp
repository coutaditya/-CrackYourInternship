// Basically inversion count implementation using merge sort technique with modification to count reverse pairs
// TC: O(nlog(n)) SC: O(n)

class Solution {
public:
    int inversion_count(vector<int> &A, int s, int e){
        int n=e-s+1;
        if(n==1){
            return 0;
        }
        int mid=s+n/2;

        int c1=inversion_count(A, s, mid-1);
        int c2=inversion_count(A, mid, e);
        int c=0;
        
        int i=s, j=mid;
        while(i<mid){
            while(j<=e && A[i]>(long)2*A[j]){
                j++;
            }
            c+=(j-mid);
            i++;
        }

        int t[n];
        i=s; j=mid;
        int k=0;
        while(j<=e && i<=mid-1){
            if(A[j]<A[i]){
                t[k]=A[j];
                j++;
            }
            else{
                t[k]=A[i];
                i++;
            }
            k++;
        }

        while(i<=mid-1){
            t[k]=A[i];
            i++;
            k++;
        }

        while(j<=e){
            t[k]=A[j];
            j++;
            k++;
        }
        
        for(int i=s; i<=e; i++){
            A[i]=t[i-s];
        }
        
        return c+c1+c2;
    }
    
    
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return inversion_count(nums, 0, n-1);
    }
};