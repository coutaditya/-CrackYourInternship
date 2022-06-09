class Solution
{
    public:
    int cal(int a, int b, char c){
        if(c=='+'){
            return a+b;
        }
        else if(c=='-'){
            return a-b;
        }
        else if(c=='*'){
            return a*b;
        }
        else{
            return a/b;
        }
    }
    
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        stack<int> in;
        int n = S.length();
        
        for(int i=0; i<n; i++){
            if(isdigit(S[i])){
                in.push(S[i]-'0');
            }
            else{
                int a = in.top();
                in.pop();
                int b = in.top();
                in.pop();
                in.push(cal(b, a, S[i]));
            }
        }
        return in.top();
    }
};