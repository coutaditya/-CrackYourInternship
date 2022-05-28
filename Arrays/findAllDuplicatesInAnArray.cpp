// TC: O(n)  SC: O(1)
// We will use the given array as vis by making an element -ve if its index has occured in the array.
// If we get a negative number stored, it means that its index has been visited before => the number has occured before so we store it. 

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[abs(nums[i])-1]<0){
                ans.push_back(abs(nums[i]));
            }
            else{
                nums[abs(nums[i])-1]*=-1;
            }
        }
        
        return ans;
    }
};