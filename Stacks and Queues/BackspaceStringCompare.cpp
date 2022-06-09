// TC: O(n) SC: O(n) solution using stacks
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> S;
        for(int i=0; i<s.length(); i++){
            if(s[i]!='#'){
                S.push(s[i]);
            }
            else{
                if(!S.empty()){
                    S.pop();
                }
            }
        }
        
        s = "";
        while(!S.empty()){
            s.push_back(S.top());
            S.pop();
        }
        
        for(int i=0; i<t.length(); i++){
            if(t[i]!='#'){
                S.push(t[i]);
            }
            else{
                if(!S.empty()){
                    S.pop();
                }
            }
        }
        
        t = "";
        while(!S.empty()){
            t.push_back(S.top());
            S.pop();
        }
        
        return (s==t);
    }
};


// TC: O(n)  SC: O(1) using two pointers
// Implementation using two pointer- 1st to traverse the string and second to store the character at given position

// Suppose 2 pointer i & k
// Start traversing the by first pointer(i) if it is # then decrease the 2nd pointer(k )(k>=0) .And if it is not # then increase the pointer(k) and store the element at k th position.
// S[k]=S[i]
// Same will be done to 2nd string And suppose its 2nd pointer is p
// If k and p are not equal means the string have differnt length. If same, then compare every element.


class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int p = 0, k = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='#'){
                if(k>0){
                    k--;
                }
            }
            else{
                s[k]=s[i];
                k++;
            }
            
        }
        
        for(int i=0; i<t.length(); i++){
            if(t[i]=='#'){
                if(p>0){
                    p--;
                }
            }
            else{
                t[p]=t[i];
                p++;
            }
        }
        
        if(p!=k) return false;
        
        for(int i=0; i<k; i++){
            if(s[i]!=t[i]){
                return false;
            }
        }
        
        return true;
    }
    
};