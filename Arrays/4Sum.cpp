// Use the same approach as 3Sum problem, just fix two number instead of 1 this time.
// TC: O(nlog(n)) [sort] + O(n^3) [3 loops]

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int> > res;
        
        if(n<4){
            return res;
        }
        
        for(int i=0; i<n-3; i++){
            if(i==0 || nums[i]!=nums[i-1]){
                for(int j=i+1; j<n-2; j++){
                    if(j==(i+1) || nums[j]!=nums[j-1]){
                        int l = j+1, h = n-1;
                        int sum = target-(nums[i]+nums[j]);
                        
                        while(l<h){
                            if((nums[l]+nums[h])==sum){
                                res.push_back({nums[i], nums[j], nums[l], nums[h]});
                                while(l<h && nums[l]==nums[l+1]){
                                    l++;
                                }
                                while(l<h && nums[h]==nums[h-1]){
                                    h--;
                                }
                                l++; h--;
                            }
                            else if((nums[l]+nums[h])<sum){
                                l++;
                            }
                            else{
                                h--;
                            }
                        }
                    }
                }
            }
        }
        
        return res;
    }
};