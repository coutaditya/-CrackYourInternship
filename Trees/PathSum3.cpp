// We start a dfs from the root node, keeping the psum in a map and for each sum, we check if psum-targetSum is present in the map or not.
// While backtracking, we remove the psum from the map

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
    void dfs(TreeNode* node, int sum, unordered_map<int, int> &m, long long &ans, long long curSum){
        if(node==NULL) return;
        
        curSum+=node->val;
        
        ans+=m[curSum-sum];
        
        if(curSum==sum) ans++;
        
        m[curSum]++;
        
        dfs(node->left, sum, m, ans, curSum);
        dfs(node->right, sum, m, ans, curSum);
        
        m[curSum]--;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<int, int> m;
        long long ans = 0, sum=0;
        dfs(root, targetSum, m, ans, sum);
        
        return ans;
    }
};