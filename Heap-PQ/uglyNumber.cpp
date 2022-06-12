class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n, 0);
        ugly[0] = 1;
        
        int t1 = 0, t2 = 0, t3 = 0;
        for(int i=1; i<n; i++){
            ugly[i] = min(ugly[t1]*2,min(ugly[t2]*3, ugly[t3]*5));
            
            if(ugly[i]==ugly[t1]*2) t1++;
            
            if(ugly[i]==ugly[t2]*3) t2++;
            
            if(ugly[i]==ugly[t3]*5) t3++;
        }
        
        return ugly[n-1];
    }
};


// BEST EXPLANATIONS:

// (1) https://leetcode.com/problems/ugly-number-ii/discuss/69368/Elegant-C%2B%2B-Solution-O(N)-space-time-with-detailed-explanation.
// (2) https://leetcode.com/problems/ugly-number-ii/discuss/69364/My-16ms-C%2B%2B-DP-solution-with-short-explanation