// Since we have a BST, start moving from the root.
// The first node that has value between given two nodes is the answer.
// TC: O(log(n)) SC:O(1)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return root;
        
        if(p->val>q->val) swap(p, q);
        
        TreeNode* temp = root;
        while(temp!=NULL){
            if(temp->val>=p->val && temp->val<=q->val){
                return temp;
            }
            else if(temp->val<p->val){
                temp = temp->right;
            }
            else{
                temp = temp->left;
            }
        }
        
        return temp;
    }
};