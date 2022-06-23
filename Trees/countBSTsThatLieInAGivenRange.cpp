class Solution{
    int count;
public:
    void dfs(Node* root, int l, int r){
        if(root==NULL) return;
        
        if(root->data>=l && root->data<=r){
            count++;
            dfs(root->left, l, r);
            dfs(root->right, l, r);
        }
        else if(root->data>r){
            dfs(root->left, l, r);
        }
        else{
            dfs(root->right, l, r);
        }
    }

    int getCount(Node *root, int l, int h){
        if(root==NULL) return 0;
        count = 0;
        dfs(root,l,h);
        return count;
    }
};
