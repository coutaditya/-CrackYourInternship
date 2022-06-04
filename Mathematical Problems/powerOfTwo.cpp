// n&(n-1) returns an integer after removing the last set bit from n.
// So if after removing the last set bit, the number becomes 0 => only one set bit => power of two
// The number must not be 0 or less initially

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        
        return ((n&(n-1))==0);
    }
};