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
public:
    bool isValid(TreeNode* root, long l, long r){
        if(root==NULL) return true;
        
        if(root->val<l || root->val>r) return false;
        
        if(root->val==INT_MAX){
            return root->right==NULL && isValid(root->left, l, r-1);
        }
        
        if(root->val==INT_MIN){
            return root->left==NULL && isValid(root->right, l+1, r);
        }
        
        return (isValid(root->left, l, root->val-1) && isValid(root->right, root->val+1, r));
    }
    
    bool isValidBST(TreeNode* root) {
        return isValid(root, INT_MIN, INT_MAX);
    }
};

// We can use LONG_MIN, LONG_MAX to avoid interger ovweflow in the corner case [INT_MAX] (node has int_max)
class Solution {
public:
    bool isValid(TreeNode* root, long l, long r){
        if(root==NULL) return true;
        
        if(root->val<l || root->val>r) return false;
        
        return (isValid(root->left, l, (long)root->val-1) && isValid(root->right, (long)root->val+1, r));
    }
    
    bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_MIN, LONG_MAX);
    }
};


// DIFFERENT APPROACH:
// We can use inorder traversal and check if it is sorted or not.
