// Standard problem of evaluation of postfix expression using stack

class Solution {
public:
    bool isOp(string s){
        if(s=="+" || s=="-" || s=="*" || s=="/"){
            return true;
        }
        else return false;
    }
    
    int eval(int a, int b, string c){
        if(c=="+") return a+b;
        if(c=="-") return a-b;
        if(c=="*") return a*b;
        else return a/b;
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto i:tokens){
            if(isOp(i)){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                
                s.push(eval(b, a, i));
            }
            else{
                s.push(stoi(i));
            }
        }
        
        return s.top();
    }
};