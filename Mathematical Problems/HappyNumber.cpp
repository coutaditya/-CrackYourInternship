// APPROACH 1:
// TC: O(k)  SC: O(k)  k = number of elements in the cycle

// Use a hash_map to store the elements as we keep moving, as soon as we get a number that already exists, we check if it is 1 or not


// APPROACH 2:
// Floyd's Cycle Detection Method
// We use a slow and fast pointer to find the cycle intersection point, if it is equal to 1, we return true else false
// TC: O(k) SC: O(1)

class Solution {
public:
    int digitSquare(int n){
        int ans = 0;
        while(n>0){
            ans+=((n%10)*(n%10));
            n/=10;
        }
        
        return ans;
    }
    
    bool isHappy(int n) {
        if(n==1){
            return true;
        }
        
        int slow = digitSquare(n), fast = digitSquare(digitSquare(n));
        while(slow!=fast){
            slow = digitSquare(slow);
            fast = digitSquare(digitSquare(fast));
            
            if(fast==1) return true;
        }
        
        return slow==1;
    }
};