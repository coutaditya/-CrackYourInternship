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
    bool ans = true;
    
    int dep(TreeNode* node){
        if(node==NULL) return 0;
        
        if(!ans) return 0;
        
        int l = dep(node->left);
        int r = dep(node->right);
        
        
        if(abs(l-r)>1){
            ans = false;
            return 0;
        }
        return max(l,r)+1;
    }
    
    bool isBalanced(TreeNode* root) {
        dep(root);
        return ans;
    }
};