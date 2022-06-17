// Function farthest returns the distance of farthest node in the left and the right subtrees,
// while also updating the ans for each node, considering the diameter passes thru it.


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
    int farthest(TreeNode* node, int &ans){
        if(node==NULL){
            return 0;
        }
        
        int l = farthest(node->left, ans);
        int r = farthest(node->right, ans);
        
        ans = max(ans, l+r);
        
        return max(l, r) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        
        int t = farthest(root, ans);
        
        return ans;
    }
};