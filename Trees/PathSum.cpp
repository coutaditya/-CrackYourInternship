// TC: O(n) SC: O(n) (recursive stack space is used)

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
    bool dfs(TreeNode* node, int target, int sum){
        if(node==NULL){
            return false;
        }
        sum+=node->val;
        
        if(node->left==NULL && node->right==NULL){
            return (sum==target);
        }
        
        return dfs(node->left, target, sum) || dfs(node->right, target, sum);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return false;
        }
        int sum = 0;
        return dfs(root, targetSum, sum);
    }
};