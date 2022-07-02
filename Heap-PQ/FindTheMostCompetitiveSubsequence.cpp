// https://leetcode.com/problems/find-the-most-competitive-subsequence/discuss/1029198/C%2B%2B-O(n)-solution-with-detailed-explanation
// We want the subsequence to contain the smallest possible numbers in increasing order but we also need to maintain the size
// So we keep a track of elements deleted while making the stack

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int> s;
        int toDelete = nums.size()-k;
        for(auto i:nums){
            while(!s.empty() && s.top()>i && toDelete){
                s.pop();
                toDelete--;
            }
            s.push(i);
        }
        
        vector<int> res;
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        vector<int> ans;
        for(int i=res.size()-1; i>=0; i--){
            if(ans.size()!=k){
                ans.push_back(res[i]);
            }
            else{
                return ans;
            }
        }
        
        return ans;
    }
};