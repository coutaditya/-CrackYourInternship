// let say you need x moves, after the x moves, all value will become min+x, where min is min value of the input.
// so the total value after move is N*(min+x), where N is size of input;
// total value after move also equal sum+x*(N-1), where sum of the sum of input;
// N*(min+x) = sum+x*(N-1) => x = sum-N*min;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0, mn = INT_MAX;
        for(auto i:nums){
            sum+=i;
            mn = min(mn, i);
        }
        
        return sum-(mn*nums.size());
    }
};