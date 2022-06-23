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
    int id;
public:
    int preorder(TreeNode* root, int k){
        if(root==NULL){
            return 0;
        }
        
        int l = preorder(root->left, k);
        if(id==k) return l;
        id++;
        if(id==k) return root->val;
        return preorder(root->right, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        id = 0;
        return preorder(root, k);
    }
};