// We store the {m, c} for each pair of points in a map
// For the max value, all the points on the line = n then (n*(n-1))/2 is stored in the map (all pairs), hence we solve the equation to get n
// TC: O(n^2) SC: O(1)
// Deal with vertical lines (m=infinity) as a corner case

// We can use a string to store m and c, because pair and vector are not hashable so unordered_map cannot be used

class Solution {
public:
    pair<float, float> eqn(vector<int> a, vector<int> b){
        pair<float, float> ans;
        
        if((a[0]-b[0])==0){
            ans.first = INT_MAX;
            ans.second = a[0];
            return ans;
        }
        
        
        ans.first = 1.0*(a[1]-b[1])/(1.0*(a[0]-b[0]));
        
        ans.second = ((float)(a[1]*b[0]-b[1]*a[0])/(float)(b[0]-a[0]));
        
        return ans;
    }
    
    int maxPoints(vector<vector<int>>& points) {
        map<pair<float, float>, int> m;
        
        int n = points.size();
        int mx = 0;
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                mx=max(mx, ++m[eqn(points[i], points[j])]);
            }
        }
        
        return (sqrt(1+8*mx)+1)/2;
        
        
    }
};