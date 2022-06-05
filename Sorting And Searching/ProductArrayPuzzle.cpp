// O(n) solution without using the division operator
// First traverse the array to store the prefix product for each index (0 to i-1)
// Then traverse from end to multiply the suffix product for each index (i+1 to n-1)

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        vector<long long int> ans(n, 1);
        long long temp = 1;
        
        for(int i=0; i<n; i++){
            ans[i] = temp;
            temp*=nums[i];
        }
        
        temp = 1;
        for(int i=n-1; i>=0; i--){
            ans[i]*= temp;
            temp*=nums[i];
        }
        
        return ans;
    }
};