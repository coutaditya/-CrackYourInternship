// TC: O(n) SC: O(1)
// Find the min sum subarray from the array suing sliding window and subtract it from the total array sum.
// It is the required answer.

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int tsum = 0;
        for(auto i:cardPoints){
            tsum+=i;
        }
        
        int win_size = n-k, sum=cardPoints[0],min_sum = INT_MAX;
        
        if(win_size==0) return tsum;
        
        int i=0, j=0;
        while(j<n){
            if((j-i+1)<win_size){
                j++;
                if(j!=n) sum+=cardPoints[j];
            }
            
            else if((j-i+1)==win_size){
                
                min_sum = min(min_sum, sum);
                
                sum-=cardPoints[i];
                i++;
            }
        }
        
        cout<<min_sum<<"\n";
        
        return tsum-min_sum;
    }
};