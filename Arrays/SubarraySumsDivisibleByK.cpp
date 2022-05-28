// The idea is to store remainder of cumulative sum with K in a map.
// Whenever we find a remainder that is already stored, we will add the frequency to the ans because adding the current element will generate subarray of remainder 0 with all previous subbarrays
// If rem till i was x and then till j was also x, the required subarray if from i+1 to j.
// Since empty array has rem = 0, we mark m[0] = 1 initially.

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int K) {
        int ans = 0;
        int csum = 0;
        
        unordered_map<int, int> m;
        m[0]=1;
        
        for(int i=0; i<nums.size(); i++){
            csum+=nums[i];
            int mod = csum%K;
            if(mod<0) mod+=K;

            if(m[mod]!=0){
                ans+=m[mod];
            }
            m[mod]++;
        }
        
        return ans;
    }
};