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
    bool equal(TreeNode* left, TreeNode* right){
        if(left==NULL || right==NULL){
            return (left==NULL && right==NULL);
        }
        
        if(left->val!=right->val) return false;
        
        return (equal(left->left, right->right) && equal(left->right, right->left)); 
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        
        return equal(root->left, root->right);
    }
};


// ITERATIVE SOLUTION(using level order traversal):
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<TreeNode*> level;
            while(!q.empty()){
                level.push_back(q.front());
                q.pop();
            }
            
            int i = 0, j = level.size() - 1;
            while(i<j){
                if(level[i]==NULL && level[j]!=NULL) return false;
                if(level[i]!=NULL && level[j]==NULL) return false;
                if(level[i]!=NULL && level[j]!=NULL && level[i]->val!=level[j]->val) return false;
                i++; j--;
            }
            
            bool last = true;
            for(int i=0; i<level.size(); i++){
                if(level[i]==NULL){
                    q.push(NULL);
                    q.push(NULL);
                    continue;
                }
                
                if(level[i]->left!=NULL || level[i]->right!=NULL) last = false;
                
                q.push(level[i]->left);
                q.push(level[i]->right);
            }
            
            if(last){
                return true;
            }
        }
        
        return true;
    }
};