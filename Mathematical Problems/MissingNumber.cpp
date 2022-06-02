// APPROACH 1 (My dumbass solution)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto i:nums){
            sum+=i;
        }
        
        return (n*(n+1))/2 - sum;
    }
};


// APPROACH 2 (Using Bit-Manipulation (very cool))

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = n;
        for(int i=0; i<n; i++){
            ans^=nums[i];
            ans^=i;
        }
        
        return ans;
    }
};