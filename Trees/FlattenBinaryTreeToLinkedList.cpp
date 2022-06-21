/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode* prev;
public:
    void inorder(TreeNode* root){
        if(root==NULL) return;
        
        if(prev!=NULL){
            prev->left = root;
        }
        
        prev = root;
        inorder(root->left);
        inorder(root->right);
    }
    
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        prev = NULL;
        inorder(root);
        
        TreeNode* temp = root;
        while(temp->left!=NULL){
            temp->right = temp->left;
            temp->left = NULL;
            temp = temp->right;
        }
        
        temp->right = NULL;
        temp->left = NULL;
        
    }
};