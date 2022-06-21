// See Striver's SDE Sheet notes (After DAY 12)
// https://www.youtube.com/watch?v=ZWGW7FminDM&ab_channel=takeUforward

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
    TreeNode* prev, *start, *middle, *last;
public:
    void inorder(TreeNode* node){
        if(node==NULL) return;
        
        inorder(node->left);
        
        if(node->val<prev->val){
            if(start==NULL){
                start = prev;
                middle = node;
            }
            else{
                last = node;
            }
        }
        
        prev = node;
        
        inorder(node->right);
    }
    
    void recoverTree(TreeNode* root) {
        prev = new TreeNode(INT_MIN);
        start = NULL;
        middle = NULL;
        last = NULL;
        inorder(root);
        
        if(start&&last) swap(start->val, last->val);
        else if(start && middle) swap(start->val, middle->val);
    }
};