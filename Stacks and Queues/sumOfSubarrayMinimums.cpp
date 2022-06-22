// Read the explanation, very interesting approach
// https://leetcode.com/problems/sum-of-subarray-minimums/discuss/178876/stack-solution-with-very-detailed-explanation-step-by-step

class Solution {
public:
    vector<int> nsl(vector<int> &arr){
        int n = arr.size();
        stack<int> s;
        vector<int> ans(n, 0);
        
        for(int i=0; i<n; i++){
            while(!s.empty() && arr[s.top()]>=arr[i]){
                s.pop();
            }
            
            if(s.empty()){
                ans[i] = i+1;
            }
            else{
                ans[i] = i-s.top();
            }
            
            s.push(i);
        }
        
        return ans;
    }
    
    vector<int> nsr(vector<int> &arr){
        int n = arr.size();
        stack<int> s;
        vector<int> ans(n, 0);
        
        for(int i=n-1; i>=0; i--){
            while(!s.empty() && arr[s.top()]>arr[i]){
                s.pop();
            }
            
            if(s.empty()){
                ans[i] = n-i;
            }
            else{
                ans[i] = s.top()-i;
            }
            
            s.push(i);
        }
        
        return ans;
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> NSL = nsl(arr);
        vector<int> NSR = nsr(arr);
        
        long long ans = 0;
        for(int i=0; i<n; i++){
            ans+= (long long)arr[i]*(long long)NSL[i]*(long long)NSR[i];
            ans%= (int)(1e9+7);
        }
        
        return ans;
    }
};