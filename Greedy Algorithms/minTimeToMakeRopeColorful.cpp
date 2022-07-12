// O(n) greedy solution
// For each subset of same letters (same balloons), add all to cost and subtract the max cost (since we'd leave the max priced one)

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();
        
        int i = 0, j = 0;
        int cost = 0, c = 0, mx = 0;
        while(i<n){
            j=i;
            c = 0;
            mx = 0;
            while(colors[i]==colors[j] && j<n){
                c+=neededTime[j];
                mx = max(mx, neededTime[j]);
                j++;
            }
            
            c-=mx;
            cost+=c;
            i = j;
        }
        
        return cost;
    }
};