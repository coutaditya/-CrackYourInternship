class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int s = 0, f = 0;
        while(s<n && nums[s]!=0){
            s++;
            f++;
        }
        
        while(f<n){
            if(nums[f]==0){
                f++;
            }
            else{
                swap(nums[s], nums[f]);
                s++;
            }
        }
    }
};