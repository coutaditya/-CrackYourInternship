// TC: Ok(log(k))  SC: O(klog(k))

#define pii pair<int, int>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pii, vector<pii>, greater<pii> > pq;
        unordered_map<int, int> m;
        
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        
        for(auto i:m){
            pq.push({i.second, i.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};