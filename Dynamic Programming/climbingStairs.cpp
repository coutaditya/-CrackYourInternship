// Basically the fibonacci problem
// Whenever we are using stored values of fixed distances from the current cell in the table, it can always be space optimised further.
// The optimal solution to fibonacci is done using matrix exponentiation (log(n))

class Solution {
public:
    int climbStairs(int n) {
        int prev1 = 1;
        int prev2 = 1;
        for(int i=2; i<n+1; i++){
            int cur = prev1+prev2;
            prev1 = prev2;
            prev2 = cur;
        }
        return prev2;
        
    }
};