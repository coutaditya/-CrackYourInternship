// https://www.geeksforgeeks.org/find-the-smallest-positive-number-missing-from-an-unsorted-array/
// Many Many approaches exist

// One such approach, segregate the non-positives and apply smallest missing number on the positive half

class Solution
{
    int segregate(int arr[], int n){
        int i=0, j=0;
        while(i<n){
            if(arr[i]<=0){
                swap(arr[i], arr[j]);
                j++;
            }
            i++;
        }
        
        return j;
    }
    
    int solve(int arr[], int n){
        for(int i=0; i<n; i++){
            if((arr[i]-1)<n && arr[arr[i]-1]>0){
                arr[arr[i]-1]*=-1;
            }
        }
        
        for(int i=0; i<n; i++){
            if(arr[i]>0){
                return i+1;
            }
        }
        
        return n+1;
    }
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) { 
        int id = segregate(arr, n);
        // cout<<id;
        
        return solve(arr+id, n-id);
    } 
};