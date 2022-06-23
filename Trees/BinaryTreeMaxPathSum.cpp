// Beautiful Explanation: https://leetcode.com/problems/binary-tree-maximum-path-sum/discuss/603072/C%2B%2B-solution-O(n)-with-detailed-explanation
// TC: O(n)  SC: O(n)  recursive stack space is called


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
    int max_sum;
public:
    int dfs(TreeNode* root){
        if(root==NULL) return 0;
        
        int l = max(dfs(root->left), 0);
        int r = max(dfs(root->right), 0);
        
        max_sum = max(max_sum, l+r+root->val);
        
        return max(l, r)+root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        max_sum = INT_MIN;
        return max(dfs(root), max_sum);
    }
};