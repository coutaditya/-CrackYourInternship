// Best Explanation: https://leetcode.com/problems/maximum-width-of-binary-tree/discuss/1803302/C%2B%2Bor-Detailed-Explanation-w-WHY-oror-Covering-Integer-overflow-conditionor-DRY-RUN
// We basically want to index the nodes (avoiding overflow, just read the damned explanation)

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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        
        queue<pair<TreeNode*, long long> > q;
        
        int ans = 0;
        q.push({root, 1});
        while(!q.empty()){
            int n = q.size();
            int minIdx = q.front().second;
            
            int mn = 0, mx = 0;
            for(int i=0; i<n; i++){
                pair<TreeNode*, long long> p = q.front();
                q.pop();
                
                p.second = p.second-minIdx+1;
                
                if(i==0){
                    mn = p.second;
                }
                
                if(i==n-1){
                    mx = p.second;
                }
                
                if(p.first->left!=NULL){
                    q.push({p.first->left, (long long)2*p.second});
                }
                if(p.first->right!=NULL){
                    q.push({p.first->right, (long long)2*p.second+1});
                }
            }
            
            ans = max(ans, (mx-mn+1));
        }
        
        return ans;
    }
};