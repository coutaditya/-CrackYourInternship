// We sort the array, then fix the first number.
// For the remaining array, we find the next 2 numbers using 2 pointers (avoiding duplicates using a while loop)

// TC: O(n^2) SC:O(1)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        vector<vector<int> > res;
        
        if(n<3) return res;
        
        for(int i=0; i<n-2; i++){
            if(i==0 || nums[i]!=nums[i-1]){
                int s = i+1, e = n-1;
                int sum = 0 - nums[i];
                
                while(s<e){
                    if((nums[s]+nums[e])==sum){
                        res.push_back({nums[i], nums[s], nums[e]});
                        
                        while(s<e && nums[s]==nums[s+1]){
                            s++;
                        }
                        while(s<e && nums[e]==nums[e-1]){
                            e--;
                        }
                        
                        s++;
                        e--;
                    }
                    
                    else if((nums[s]+nums[e])<sum){
                        s++;
                    }
                    else{
                        e--;
                    }
                }
            }
        }
        
        return res;
    }
};