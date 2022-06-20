/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
bool solve(Node* root, int l, int r){
    if(root==NULL) return false;
    if(root->left==NULL && root->right==NULL && l>=r) return true;
    
    return solve(root->left, l, root->data-1)||solve(root->right, root->data+1, r);
}

bool isDeadEnd(Node *root){
    if(root==NULL) return false;
    
    return solve(root, 1, INT_MAX);
}