// Since the element has to occur more than (n/2) times, the count for it will always be >=1 at the end and it will be stored in the ele variable
// TC: O(n) SC: O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int ele=0, count=0;
        for(int i=0; i<n; i++){
            if(count==0){
                ele=nums[i];
            }
            if(ele==nums[i]){
                count++;
            }
            else{
                count--;
            }
        }
        return ele;
    }
};