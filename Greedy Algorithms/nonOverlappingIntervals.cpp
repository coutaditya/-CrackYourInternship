bool comp(pair<int, int> a, pair<int, int> b){
    return a.second<b.second;
}

class Solution {
public:   
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==0) return 0;
        
        // Using pair kyuki ek bada testcase TLE de raha tha when sorting by comparing vectors
        vector<pair<int, int> > v(intervals.size());
        int x = 0;
        for(auto i:intervals){
            v[x++] = {i[0], i[1]};
        }
        
        sort(v.begin(), v.end(), comp);
        int ans = 0;
        int end = v[0].second;
        
        for(int i=1; i<v.size(); i++){
            if(v[i].first<end){
                ans++;
            }
            else{
                end = v[i].second;
            }
        }
        
        return ans;
    }
};