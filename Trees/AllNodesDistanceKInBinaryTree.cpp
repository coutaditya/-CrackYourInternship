// Store the parent of each node in a map (O(n))
// Then start from the target node and do a bfs (downward using child nodes and upwards using par nodes) also maintain a vis array, to avoid going to the same node again

// TC: O(n)  SC: O(n)


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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> par;
        unordered_map<TreeNode*, bool> vis;
        
        vector<int> ans;
        int level = 0;
        
        queue<TreeNode*> q;
        q.push(root);
        
        // Set the parent of each node
        par[root] = NULL;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            if(node->left){
                par[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                par[node->right] = node;
                q.push(node->right);
            }
        }
        
        q.push(target);
        vis[target] = true;
        while(!q.empty()){
            if(level++ == (k)) break;
            
            int n = q.size();
            
            for(int i=0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left && !vis[node->left]){
                    q.push(node->left);
                    vis[node->left] = true;
                }
                if(node->right && !vis[node->right]){
                    q.push(node->right);
                    vis[node->right] = true;
                }
                if(par[node] && !vis[par[node]]){
                    q.push(par[node]);
                    vis[par[node]] = true;
                }
            }
            
        }
        
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        
        return ans;
    }
};