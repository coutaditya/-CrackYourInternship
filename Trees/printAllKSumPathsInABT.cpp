// Recursive Backtracking Solution (Problem is similar to path sum 3-leetcode)
// Amazon Interview Question
// Time Complexity: O(n*h*h)  , as maximum size of path vector can be h 
// Space Complexity: O(h)

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
    unordered_map<int, vector<int> > m;
    vector<vector<int> > ans;
public:
    void dfs(TreeNode* root, int target, int sum, vector<int> &path){
        if(root==NULL) return;
        
        sum+=root->val;
        path.push_back(root->val);
        m[sum].push_back(path.size()-1);
        
        if(m[sum-target].size()>0){
            for(auto i:m[sum-target]){
                vector<int> temp;
                for(int j = i+1; j<path.size(); j++){
                    temp.push_back(path[j]);
                }
                if(temp.size()>0) ans.push_back(temp);
            }
        }
        
        dfs(root->left, target, sum, path);
        dfs(root->right, target, sum, path);
        
        path.pop_back();
        m[sum].pop_back();
    }
    
    vector<vector<int> > pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        
        m[0].push_back(-1);
        vector<int> path;
        dfs(root, targetSum, 0, path);
        
        return ans;
    }
};