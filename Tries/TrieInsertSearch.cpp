//Function to insert string into TRIE.
void insert(struct TrieNode *root, string key)
{
    TrieNode* temp = root;
    for(auto i:key){
        if(temp->children[i-'a']==NULL){
            temp->children[i-'a'] = new TrieNode();
        }
        temp = temp->children[i-'a'];
    }
    temp->isLeaf = true;
}

//Function to use TRIE data structure and search the given string.
bool search(struct TrieNode *root, string key) 
{
    TrieNode* temp = root;
    for(auto i:key){
        if(temp->children[i-'a']==NULL) return false;
        
        temp = temp->children[i-'a'];
    }
    
    return temp->isLeaf;
}