//In-order traversal of BST yields sorted sequence. 
// So, we just need to subtract the previous element from the current one, and keep track of the minimum. 
// We need O(1) memory as we only store the previous element, but we still need O(h) for the stack.


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
    void inorder(TreeNode* node, int &val, int &ans){
        if(node->left!=NULL){
            inorder(node->left, val, ans);
        }
        if(val>=0) ans = min(node->val-val, ans);
        val = node->val;
        if(node->right!=NULL){
            inorder(node->right, val, ans);
        }
    }
    
    int getMinimumDifference(TreeNode* root) {
        if(root==NULL) return 0;
        int ans = INT_MAX;
        int val = -1;
        inorder(root, val, ans);
        return ans;
    }
};
