class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int s = 0, f = 1;
        while(f<nums.size()){
            if(nums[f]!=nums[f-1]){
                nums[s+1]=nums[f];
                s++;
            }
            f++;
        }
        return s+1;
    }
};