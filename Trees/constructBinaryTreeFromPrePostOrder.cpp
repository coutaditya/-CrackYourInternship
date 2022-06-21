// We move thru the preorder array and for each node, we check if its index in the postorder array <= index of its prev node
// If yes, it means the node is child of its prev node
// Else, we backtrack to the earlier node
// See this explanation: https://www.youtube.com/watch?v=hS0d0jnyToQ&ab_channel=EricProgramming

// TC: O(n)  SC: O(n)

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
private:
    int idx, n;
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        n = preorder.size();
        idx = 0;
        vector<int> post(n+1, 0);
        for(int i=0; i<n; i++){
            post[postorder[i]] = i;
        }
        return dfs(n, post, preorder);
    }
    
    TreeNode* dfs(int prevIdx, vector<int> post, vector<int> preorder){
        if(idx==n) return NULL;
        
        int curIdx = post[preorder[idx]];
        int curVal = preorder[idx];
        if(curIdx>prevIdx){
            return NULL;
        }
        else{
            idx++;
            
            TreeNode* node = new TreeNode(curVal);
            
            node->left = dfs(curIdx, post, preorder);
            node->right = dfs(curIdx, post, preorder);
            
            return node;
        }
    }
};