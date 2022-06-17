// If you draw the 3 or 4 level, just to make sure, binary tree and invert it on a paper, 
// you will easily see that all have to be done is to swap kids for each node. 
// This can be done many ways: recursion or using queue to store nodes of one level. 
// Recursion is not good way to go due to performance overhead and risk to run it against huge tree. 
// With standard queue solution looks simple robust and runs faster.


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


// RECURSIVE SOLUTION:
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL){
            return root;
        }
        
        TreeNode* l = invertTree(root->left);
        TreeNode* r = invertTree(root->right);
        
        root->left = r;
        root->right = l;
        
        return root;
    }
};

// INTERATIVE SOLUTION (Using queue):
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL){
            return root;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left!=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                q.push(node->right);
            }
            
            TreeNode* t = node->left;
            node->left = node->right;
            node->right = t;
        }
        return root;
    }
};