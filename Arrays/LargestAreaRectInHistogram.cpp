// Find NSL and NSR for each index using stacks and then calculate area for each index as maximum height  = height[i]*(NSR[i]-NSL[i]-1)
// See Stacks Notes for NSL/NSR

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        vector<int> NSL(n,0);
        vector<int> NSR(n,0);
        
        stack<int> s;
        
        NSL[0] = -1;
        s.push(0);
        for(int i=1; i<n; i++){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            
            if(s.empty()){
                NSL[i] = -1;
            }
            else{
                NSL[i] = s.top();
            }
            
            s.push(i);
        }
        
        while(!s.empty()){
            s.pop();
        }
        
        NSR[n-1] = n;
        s.push(n-1);
        for(int i=n-2; i>=0; i--){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            
            if(s.empty()){
                NSR[i] = n;
            }
            else{
                NSR[i] = s.top();
            }
            
            s.push(i);
        }
        
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            ans = max(ans, (NSR[i]-NSL[i]-1)*heights[i]);
        }
        
        return ans;
            
    }
};