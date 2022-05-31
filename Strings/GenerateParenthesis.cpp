// Standard IP/OP Method problem by Aditya Verma Sir (check Recursion notes)

class Solution {
public:
    void solve(int op, int cl, int n, string s, vector<string> &v){
        if(op==n && cl==n){
            v.push_back(s);
            return;
        }
        
        if(op<n){
            solve(op+1, cl, n, s+"(", v);
        }
        
        if(cl<op){
            solve(op, cl+1, n, s+")", v);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        solve(0, 0, n, "", v);
        return v;
    }
};