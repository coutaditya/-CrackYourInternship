// My Ghisa-Pita Solution(notso much actually, inorder traverse karke pick kar rahe hai log):
// We move till root lies between [low, high]
// Then we move in left and right subtrees to locate low and high and add appropriate subtrees into the sum.

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
    int subtreeSum(TreeNode* node){
        if(node==NULL) return 0;
        
        return subtreeSum(node->left)+subtreeSum(node->right)+node->val;
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL){
            return 0;
        }
        
        if(root->val>high) return rangeSumBST(root->left, low, high);
        else if(root->val<low) return rangeSumBST(root->right, low, high);
        else{
            int ans = 0;
            TreeNode* t = root->right;
            while(t!=NULL){
                if(t->val<=high){
                    ans+=t->val;
                    ans+=subtreeSum(t->left);
                    t = t->right;
                }
                else{
                    t = t->left;
                }
            }
            t = root->left;
            while(t!=NULL){
                if(t->val>=low){
                    ans+=t->val;
                    ans+=subtreeSum(t->right);
                    t = t->left;
                }
                else{
                    t = t->right;
                }
            }
            
            ans+=root->val;
            return ans;
        }
    }
}; 


// RECURSZIVE:
