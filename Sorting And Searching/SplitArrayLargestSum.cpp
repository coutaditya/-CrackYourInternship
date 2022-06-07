// Binary Search On Answer

class Solution {
public:
    bool check(vector<int> &nums, int x, int m){
        int sub_arr = 1;
        int sum = 0;
        
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            if(sum>x){
                sub_arr++;
                sum = nums[i];
            }
        }
        
        return (sub_arr<=m);
    }
    
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        
        int s = INT_MIN;
        int e = 0;
        for(int i=0; i<n; i++){
            s = max(nums[i], s);
            e+=nums[i];
        }
    
        int ans = -1;
        while(s<=e){
            int mid = s+(e-s)/2;
            
            if(check(nums, mid, m)){
                ans = mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        
        return ans;
    }
};