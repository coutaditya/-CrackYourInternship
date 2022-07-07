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

class WordDictionary {
    node* root;
public:
    WordDictionary() {
        root = new node();
    }
    
    void addWord(string word) {
        node* temp = root;
        for(auto s:word){
            if(temp->links[s-'a']==NULL){
                temp->links[s-'a'] = new node();
            }
            temp = temp->links[s-'a'];
        }
        temp->isEnd = true;
    }
    
    bool dfs(string &word, int i, node* temp){
        if(i==word.length()){
            return temp->isEnd;
        }
        
        if(word[i]!='.'){
            if(temp->links[word[i]-'a']==NULL) return false;
            
            return dfs(word, i+1, temp->links[word[i]-'a']);
        }
        else{
            
            for(int j=0; j<26; j++){
                if(temp->links[j]!=NULL){
                    if(dfs(word, i+1, temp->links[j])){
                        return true;   
                    }
                }
                
            }
            return false;
        }
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};
