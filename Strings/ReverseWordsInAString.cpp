// My Solution: Using a stack (pretty obvious)
// TC: O(n) SC:O(n)

class Solution {
public:
    string reverseWords(string s) {
        string ns = "";
        
        int x = 0;
        while(s[x]==' '){
            x++;
        }
        
        for(int i=x; i<s.length(); i++){
            if(i!=0 && s[i-1]==' ' && s[i]==' '){
                continue;
            }
            else{
                ns.push_back(s[i]);
            }
        }
        
        if(ns[ns.length()-1]!=' '){
            ns.push_back(' ');
        }
        
        stack<string> S;
        int id = 0;
        for(int i=0; i<ns.length(); i++){
            if(ns[i]==' '){
                S.push(ns.substr(id, i-id));
                id = i+1;
            }
        }
        
        string ans = "";
        while(!S.empty()){
            ans.append(S.top());
            S.pop();
            ans.push_back(' ');
        }
        
        ans.pop_back();
        return ans;
    }
};


// Better Solution: Reverse the words in place, shift the words so that there are no extra white spaces and then in the end reverse the whole string
// TC: O(n) SC:O(1)

class Solution {
public:

    // function to reverse any part of string from i to j (just one word or entire string)
    void reverseword(string &s, int i, int j){
        while(i<j){
          char t=s[i];
          s[i++]=s[j];
          s[j--]=t;
        } 
    }
    
    void reverseWords(string &s) {
        
        int i=0, j=0;
        int l=0;
        int len=s.length();
        int wordcount=0;
        
        while(true){
            while(i<len && s[i] == ' ') i++;  // skip spaces in front of the word
            if(i==len) break;
            if(wordcount) s[j++]=' ';
            l=j;
            while(i<len && s[i] != ' ') {s[j]=s[i]; j++; i++;} 
            reverseword(s,l,j-1);                // reverse word in place
            wordcount++;
            
        }
        
        s.resize(j);                           // resize result string
        reverseword(s,0,j-1);                  // reverse whole string
    }
};
