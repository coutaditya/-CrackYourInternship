class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s = nums[0], f = nums[0];
        f = nums[nums[f]];
        s = nums[s];
        while(s!=f){
            s = nums[s];
            f = nums[nums[f]];
        }
        f = nums[0];
        while(s!=f){
            s = nums[s];
            f = nums[f];
        }
        
        return s;
    }
};