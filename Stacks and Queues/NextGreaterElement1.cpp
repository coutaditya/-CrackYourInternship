// Basically NGR code for random indices

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        stack<int> s;
        int n = nums2.size();
        m[nums2[n-1]] = -1;
        s.push(n-1);
        for(int i = n-2; i>=0; i--){
            while(!s.empty() && nums2[s.top()]<=nums2[i]){
                s.pop();
            }
            if(s.empty()){
                m[nums2[i]]=-1;
            }
            else{
                m[nums2[i]]=s.top();
            }
            s.push(i);
        }
        
        vector<int> ans(nums1.size(), 0);
        for(int i=0; i<nums1.size(); i++){
            if(m[nums1[i]]!=-1)
                ans[i] = (nums2[m[nums1[i]]]);
            else    
                ans[i] = (-1);
        }
        
        return ans;
    }
};