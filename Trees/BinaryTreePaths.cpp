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
    void dfs(vector<string> &ans, string s, TreeNode* node){
        if(node==NULL) return;
        
        if(node->left==NULL && node->right==NULL){
            s.append("->"+to_string(node->val));
            ans.push_back(s);
            return;
        }
        
        s.append("->"+to_string(node->val));
        dfs(ans, s, node->left);
        dfs(ans, s, node->right);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        string s = to_string(root->val);
        
        vector<string> ans;
        
        if(root->left==NULL && root->right==NULL){
            ans.push_back(s);
            return ans;
        }
        dfs(ans, s, root->left);
        dfs(ans, s, root->right);
        
        return ans;
    }
};