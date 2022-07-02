// https://leetcode.com/problems/maximum-product-subarray/discuss/203013/C%2B%2B-O(N)-time-O(1)-space-solution-with-explanation
// READ THISS FFS

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int maxProd = 1, minProd = 1;
        
        for(auto i:nums){
            if(i<0) swap(maxProd, minProd);
            
            maxProd = max(maxProd*i, i);
            minProd = min(minProd*i, i);
            
            ans = max(ans, maxProd);
        }
        
        return ans;
    }
};