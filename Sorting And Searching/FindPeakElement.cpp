// Using Ternary Search (useless, can be solved using binary search aswell (see BS notes))

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = n-1;
        
        if(n==1 || nums[0]>nums[1]){
            return 0;
        }
        
        if(nums[n-1]>nums[n-2]){
            return n-1;
        }
        
        while(s<e){
            int mid1 = s+(e-s)/3;
            int mid2 = s+2*(e-s)/3;
            
            if(mid1!=0 && mid1!=(n-1) && (nums[mid1]>nums[mid1-1] && nums[mid1]>nums[mid1+1])){
                return mid1;
            }
            
            if(mid2!=0 && mid2!=(n-1) && (nums[mid2]>nums[mid2-1] && nums[mid2]>nums[mid2+1])){
                return mid2;
            }
            
            if(nums[mid1]<nums[mid2]){
                s=mid1;
            }
            else{
                e=mid2;
            }
        }
        
        return s;
    }
};

// Binary Search Solution
// If nums[mid] < nums[mid+1], then there has to be a peak element in the right side of mid.
// Either the numbers increase until we reach the end and then the last element will be a peak, 
// or at some point a number gets smaller and right there we will have a peak.
// Same for the left side of mid.

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lo = 0, hi = nums.size()-1, mid;
        
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            if (nums[mid] < nums[mid + 1]) 
                lo = mid + 1;
            else hi = mid;
        }
        
        return lo;
    }
};