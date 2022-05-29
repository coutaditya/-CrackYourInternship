// Similar to subarraySumDivisibleByK Problem
// We store the prefix sums in a map, for each psum, we check if csum-k is already present (and how many times)
// We add that to the answer and increment the count of m[psum] by one
// TC: O(n) SC: O(n)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> m;
        int ans = 0;
        m[0] = 1;
        int csum = 0;
        for(int i=0; i<n; i++){
            csum+=nums[i];
            if(m[csum-k]!=0){
                ans+=m[csum-k];
            }
            m[csum]++;
        }
        
        return ans;
    }
};