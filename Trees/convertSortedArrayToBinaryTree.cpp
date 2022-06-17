// We chose the mid element to be inserted in the tree everytime then move to the left and right halves.
// When size of a half <= 2, we can insert them in any order (since difference of 1 in heights is allowed)


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
    TreeNode* insert(TreeNode* root, int val){
        TreeNode* node = new TreeNode(val);
        
        if(root==NULL){
            root = node;
            return root;
        }
        else{
            TreeNode* t = root;
            while(true){
                if(t->val>=val){
                    if(t->left==NULL){ 
                        t->left = node;
                        break;
                    }
                    else t = t->left;
                }
                else{
                    if(t->right==NULL){
                        t->right = node;
                        break;
                    }
                    else t = t->right;
                } 
            }
            return root;
        }
    }
    
    TreeNode* makeTree(vector<int> &nums, TreeNode* t, int l, int r){
        if((r-l+1)<=2){
            for(int i=l; i<=r; i++){
                t = insert(t, nums[i]);
            }
            return t;
        }
        
        else{
            int mid = l+(r-l)/2;
            t = insert(t, nums[mid]);
            t = makeTree(nums, t, l, mid-1);
            t = makeTree(nums, t, mid+1, r);
            
            return t;
        }
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        
        TreeNode* root = NULL;
        root = makeTree(nums, root, 0, nums.size()-1);
        return root;
    }
};