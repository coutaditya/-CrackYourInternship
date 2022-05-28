// We want to buy at dip and sell at a peak, so for any day if yesterday was cheaper, we will consider buy yesterday and sell today.
// This give us the global maximum as well
// Make a graph of prices on different days to visualise how it works.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        for(int i=1; i<n; i++){
            if(prices[i]>prices[i-1]){
                ans+=(prices[i]-prices[i-1]);
            }
        }
        return ans;
    }
};