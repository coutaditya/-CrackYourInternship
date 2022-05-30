// The equation becomes xj+yj - (xi-yi) if we assume (xj>xi) i.e. j is the current point and i is a previous point.
// We want to minimise the value of (xi-yi) so we will use the approach of min in a sliding window 
// Maintain a deque such that the front stores the min value and the next element is the next min (see sliding window notes)

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        
        deque<pair<int, int> > q;
        
        int i=0;
        int ans = INT_MIN;
        
        while(i<n){
            while(!q.empty() && (points[i][0]-q.front().first)>k){
                q.pop_front();
            }
            
            if(!q.empty()){
                pair<int, int> a = q.front(), b = {points[i][0], points[i][1]} ;
            
                ans = max(ans, b.first+b.second - (a.first-a.second));
            }
            
            while(!q.empty()&&(q.back().first-q.back().second)>(points[i][0]-points[i][1])){
                q.pop_back();
            }
            
            q.push_back({points[i][0], points[i][1]});
            i++;
        }
        
        return ans;
    }
};