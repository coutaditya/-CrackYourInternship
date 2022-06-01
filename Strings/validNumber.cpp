// My Ghisa-Pita Solution (took 13 wrong submissions to get accepted but this was faster than 100%)

class Solution {
public:
    bool isInteger(string s){
        int n = s.length();
        if(n==0) return false;
        int i=0;
        if(s[i]=='+' || s[i]=='-'){
            i++;
        }
        
        if(i==n) return false;
        
        while(i<n){
            if(!isdigit(s[i])){
                return false;
            }
            i++;
        }
        
        return true;
    }
    
    bool isDecimal(string s){
        if(s=="." || s=="-." || s=="+.") return false;
        
        int n = s.length();
        if(n==0) return false;
        int i = 0;
        
        if(s[i]=='+' || s[i]=='-'){
            i++;
        }
        
        int k = i;
        
        if(i==n) return false;
        
        while(i<n && s[i]!='.'){
            i++;
        }
        
        if(!isInteger(s.substr(0,i)) && s.substr(k,i-k)!=""){
            return false;
        }
        i++;
        
        // if(i==n) return false;
        
        while(i<n){
            if(!isdigit(s[i])){
                return false;
            }
            i++;
        }
        
        return true;
    }
    
    bool isNumber(string s) {
        if(isDecimal(s) || isInteger(s)){
            return true;
        }
        
        int n = s.length();
        
        int i = 0;
        while(i<n && s[i]!='E' && s[i]!='e'){
            i++;
        }
        
        if(i==n){
            return false;
        }
        
        if(!isDecimal(s.substr(0,i)) && !isInteger(s.substr(0, i))){
            return false;
        }
        
        if(!isInteger(s.substr(i+1, (n-i-1)))){
            return false;
        }
        
        return true;
    }
};