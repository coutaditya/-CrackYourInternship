// do a preorder traversal and change nodes accordingly

class Solution
{
    Node* head, * temp;
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    void preorder(Node* root){
        if(root==NULL) return;
        
        preorder(root->left);
        if(head==NULL){
            head = root;
            temp = root;
        }
        else{
            temp->right = root;
            root->left = temp;
            temp = root;
        }
        preorder(root->right);
    }
    
    Node * bToDLL(Node *root){
        if(root==NULL) return root;
        
        head = NULL;
        temp = NULL;
        preorder(root);
        return head;
    }
};