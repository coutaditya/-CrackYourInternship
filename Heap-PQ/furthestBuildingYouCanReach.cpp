// Store the differences (if positive) in  a max-pq
// If sum>bricks, we subtract the top from pq as a ladder is used for that till no more ladders are available

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        
        int i = 0, n = heights.size();
        int sum = 0;
        while(i<(n-1)){
            if(heights[i+1]>heights[i]){
                sum+=(heights[i+1]-heights[i]);
                // cout<<i<<" = "<<sum<<"\n";
                pq.push((heights[i+1]-heights[i]));
                if(bricks<sum){
                    if(ladders>0){
                        sum-=pq.top();
                        pq.pop();
                        ladders--;
                    }
                    else{
                        return i;
                    }
                }
            }
            i++;
        }
        return n-1;
    }
};