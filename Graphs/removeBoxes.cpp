// SOLUTION EXPLANATION: https://www.youtube.com/watch?v=ncW3zm_J3qY&ab_channel=CodingDecoded

class Solution {
public:
    int dfs(int streak, int l, int r, vector<int> &boxes, vector<vector<vector<int> > > &t){
        if(l>r) return 0;
        
        if(l==r)  return (streak+1)*(streak+1);
        
        if(t[l][r][streak]!=-1){
            return t[l][r][streak];
        }
        
        int mx = (streak+1)*(streak+1) + dfs(0, l+1, r, boxes, t);
        
        for(int i=l+1; i<=r; i++){
            if(boxes[i]==boxes[l]){
                mx = max(mx, dfs(0, l+1, i-1, boxes, t)+dfs(streak+1, i, r, boxes, t));
            }
        }
        
        return t[l][r][streak] = mx;
    }
    
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        
        int streak = 0;
        vector<vector<vector<int> > > t(n, vector<vector<int> >(n, vector<int>(n+1, -1)));
        
        return dfs(streak, 0, n-1, boxes, t);
    }
};