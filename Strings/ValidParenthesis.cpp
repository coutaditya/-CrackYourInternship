class Solution {
public:
    char opp(char c){
        if(c=='(') return ')';
        else if(c=='{') return '}';
        else return ']';
    }
    
    bool isValid(string s) {
        stack<char> S;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                S.push(s[i]);
            }
            else{
                if(S.empty() || opp(S.top())!=s[i]){
                    return false;
                }
                else{
                    S.pop();
                }
            }
        }
        
        if(S.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};