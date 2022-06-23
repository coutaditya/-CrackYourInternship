class Solution{
public:
    //Function that constructs BST from its preorder traversal.
    Node* insert(Node* root, int d){
        Node* t = newNode(d);
        if(root==NULL){
            return t;
        }
        
        if(root->data>=d){
            root->left = insert(root->left, d);
        }
        else{
            root->right = insert(root->right, d);
        }
    }
    
    
    Node* post_order(int pre[], int size)
    {
        if(size==0) return NULL;
        Node* root = newNode(pre[0]);
        
        for(int i=1; i<size; i++){
            root = insert(root, pre[i]);
        }
        
        return root;
    }
};