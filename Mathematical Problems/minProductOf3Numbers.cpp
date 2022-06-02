APPROACH 1:
Use for loops to find greatest 3 numbers and smallest 2 numbers (since prod of two -ve is +ve)
TC: O(n) SC: O(1)

APPROACH 2:
Dynamic Programming (for prod of k, use k+1 levels in DP table)

f[2][4] is used to store max array and min array. 4 is level, if we want to find out 5 numbers multiplication of an array, then level would be 6. (using 0 as multiplication factor). namely f[2][6].

f[0][1] is ONE NUMBER maximum multiplation for array
f[0][2] is TWO NUMBERS maximum multiplation for array
f[0][3] is THREE NUMBERS maximum multiplation for array
f[1][1] is ONE NUMBER minimum multiplication for array
f[1][2] is TWO NUMBERS minimum multiplation for array
f[1][3] is THREE NUMBERS minimum multiplation for array
Moreover, we use reverse loop for levels, which is a common space optimaizaiton. And in order not to overflow, we use f[0][j - 1] == INT_MIN to jump situation.

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int f[2][4]; // DP table with 4 levels (since prod of 3 numbers is req)
        f[0][0] = 1;
        f[1][0] = 1;
        
        for(int i=1; i<4; i++){
            f[0][i] = INT_MIN;
            f[1][i] = INT_MAX;
        }
        
        for(int i=0; i<nums.size(); i++){
            for(int j=3; j>0; j--){
                if(f[0][j-1]==INT_MIN){
                    continue;
                }
                
                f[0][j] = max(f[0][j], max(f[0][j-1]*nums[i], f[1][j-1]*nums[i]));
                f[1][j] = min(f[1][j], min(f[0][j-1]*nums[i], f[1][j-1]*nums[i]));
            }
        }
        
        return f[0][3];
    }
};