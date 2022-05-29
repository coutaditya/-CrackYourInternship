// TC: O(n) SC: O(1)
// We define a variable reach that stores the max index that can be reached from indices upto i
// We will move i<=reach, so if i==n at the end i.e. reach >= n we will return true else false


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        int reach = 0; // maximum index that can be reached
        int i=0;
        for(i=0; i<n && i<=reach; i++){
            reach = max(i+nums[i], reach);
        }
        
        return (i==n);
    }
};