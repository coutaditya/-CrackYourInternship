// Start comparing the elements and filling the nums1 array from the end. There will be no overlap with nums1 original elements
// because the space for n elements of nums2 is there so if we reach any elements of nums1, it would have been compared already and put in correct position
// TC: O(n+m) SC:O(1)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = n+m-1, i=m-1, j=n-1;
        
        while(j>=0 && i>=0){
            if(nums1[i]>nums2[j]){
                nums1[k]=nums1[i];
                k--;
                i--;
            }
            else{
                nums1[k]=nums2[j];
                j--;
                k--;
            }
        }
        while(j>=0){
            nums1[k]=nums2[j];
            j--;
            k--;
        }
    }
};