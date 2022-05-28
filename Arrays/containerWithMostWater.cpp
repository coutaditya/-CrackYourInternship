// TC: O(n) SC: O(1)
// We start with the widest container (i==0, j==n-1). The water contained will increase with decrease in width only if
// the min of height of the left and rightmost partitions is greater than the previous min.
// Hence we will shift the partitions till we get a partition of greater height and then compare the amount stored.


class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int ans = 0;
        
        while(i<j){
            int h = min(height[i], height[j]);
            ans = max(ans, (j-i)*h);
            
            while(i<j && height[i]<=h) i++;
            while(i<j && height[j]<=h) j--;
        }
        
        return ans;
    }
};