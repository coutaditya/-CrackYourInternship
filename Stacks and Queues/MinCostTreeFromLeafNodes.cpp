// https://www.youtube.com/watch?v=pYs3qj42h3c&ab_channel=ParasSaini

class Solution {
public:
    pair<int, int> solve(int s, int e, vector<int> &arr, vector<vector<pair<int, int> > >&t){
        if(s==e){
            return {arr[s], 0};
        }
        
        if(t[s][e].first!=-1 && t[s][e].second!=-1){
            return t[s][e];
        }
        
        int mx = 0, ans = INT_MAX;
        
        for(int i = s+1; i<=e; i++){
            pair<int, int> p1, p2;
            p1 = solve(s, i-1, arr, t);
            p2 = solve(i, e, arr, t);
            
            if(ans>(p1.second+p2.second+p1.first*p2.first)){
                mx = max(p1.first, p2.first);
                ans = (p1.second+p2.second+p1.first*p2.first);
            }
        }
        
        return t[s][e] = {mx, ans};
    }
    
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        
        vector<vector<pair<int, int> > > t(n, vector<pair<int, int> >(n, {-1, -1}));
        
        return solve(0, n-1, arr, t).second;
    }
};