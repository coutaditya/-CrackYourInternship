class Solution {
public:
    void sortColors(vector<int>& nums) {
        int s = 0, e = nums.size()-1;
        
        //put all 0s in place
        while(s<=e){
            if(nums[s]==0){
                s++;
            }
            else{
                if(nums[e]==0){
                    swap(nums[s], nums[e]);
                    s++;
                    e--;
                }
                else{
                    e--;
                }
            }
        }
        
        //Now that all zeroes are in place, put 1s in place
        e=nums.size()-1;
        while(s<=e){
            if(nums[s]==1){
                s++;
            }
            else{
                if(nums[e]==1){
                    swap(nums[s], nums[e]);
                    s++;
                    e--;
                }
                else{
                    e--;
                }
            }
        }
    }
};