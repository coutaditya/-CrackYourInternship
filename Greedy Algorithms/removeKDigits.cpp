// I DID NOT/COULD NOT COME UP WITH THIS SOLUTION
// READ THIS: https://leetcode.com/problems/remove-k-digits/discuss/1779458/C%2B%2B-oror-Easy-To-Understand-oror-Stack-oror-Short-and-Simple


class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.length()) return "0";
        if(k==0) return num;
        
        stack<char> s;
        s.push(num[0]);
        for(int i=1; i<num.size(); i++){
            while(!s.empty() && num[i]<s.top() && k){
                s.pop();
                k--;
            }
            s.push(num[i]);
            
            if(s.size()==1 && num[i]=='0'){
                s.pop();
            }
        }
        while(k && !s.empty()){
            s.pop();
            k--;
        }
        string ans = "";
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        
        if(ans.size()==0) return "0";
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};