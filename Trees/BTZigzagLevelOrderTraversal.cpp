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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool ltr = true;
        while(!q.empty()){
            int n = q.size();
            vector<int> v;
            for(int i=0; i<n; i++){
                TreeNode* t = q.front();
                v.push_back(t->val);
                q.pop();
                
                if(t->left!=NULL) q.push(t->left);
                if(t->right!=NULL) q.push(t->right);
                
            }
            if(ltr){
                ans.push_back(v);
            }
            else{
                reverse(v.begin(), v.end());
                ans.push_back(v);
            }
            ltr=!ltr;
        }
        
        return ans;
    }
};