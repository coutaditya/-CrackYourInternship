class node{
public:
    node* links[26];
    bool isEnd;
    
    node(){
        for(int i=0; i<26; i++){
            links[i] = NULL;
        }
        isEnd = false;
    }
};

class Trie{
    
public:
    node* root;
    Trie(){
        root = new node();
    }
    
    void add(string s){
        node* temp = root;
        for(auto i:s){
            if(temp->links[i-'a']==NULL){
                temp->links[i-'a'] = new node();
            }
            temp = temp->links[i-'a'];
        }
        temp->isEnd = true;
    }
    
    bool search(string s, int i, node* temp){
        if(i==s.length()){
            return temp->isEnd;
        }
        
        if(temp->links[s[i]-'a']==NULL) return false;
        
        if(temp->links[s[i]-'a']->isEnd==true){
            return (search(s, i+1, root)||search(s, i+1, temp->links[s[i]-'a']));
        }
        else return search(s, i+1, temp->links[s[i]-'a']);
    }
};

class Solution{
    public:
    // A : given string to search
    // B : vector of available strings
    
    int wordBreak(string A, vector<string> &B) {
        Trie t;
        for(auto i:B){
            t.add(i);
        }
        
        return t.search(A, 0, t.root);
    }
};