// https://www.youtube.com/watch?v=VBxiavZYfoA&ab_channel=KartikArora
// DP on Trees (3D DP) - watch the explanation

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
const int inf = 1e5+1;

class Solution {
    map<pair<TreeNode*, pair<bool, bool> >, int > m;
public:
    int solve(TreeNode* root, bool curCam, bool parCam){
        if(root==NULL){
            if(curCam) return inf;
            else return 0;
        }
        
        if(root->left==NULL && root->right==NULL){
            if(curCam && parCam){
                return 1;
            }
            else if(curCam){
                return 1;
            }
            else if(parCam){
                return 0;
            }
            else return inf;
        }
        
        if(m.find({root, {curCam, parCam}})!=m.end()){
            return m[{root, {curCam, parCam}}];
        }
        
        if(curCam && parCam){
            return m[{root, {curCam, parCam}}] = 1 + min(solve(root->left, 1,1), solve(root->left, 0, 1)) + min(solve(root->right, 1, 1), solve(root->right, 0, 1));
        }
        else if(curCam){
            return m[{root, {curCam, parCam}}] = 1 + min(solve(root->left, 1,1), solve(root->left, 0, 1)) + min(solve(root->right, 1, 1), solve(root->right, 0, 1));
        }
        else if(parCam){
            return m[{root, {curCam, parCam}}] = min(solve(root->left, 1,0), solve(root->left, 0, 0)) + min(solve(root->right, 1, 0), solve(root->right, 0, 0));
        }
        else{
            return m[{root, {curCam, parCam}}] = min(solve(root->left, 1, 0)+min(solve(root->right, 1, 0), solve(root->right, 0, 0)), solve(root->right, 1, 0)+min(solve(root->left, 1, 0), solve(root->left, 0, 0)));
        }
        
    }
    
    int minCameraCover(TreeNode* root) {
        m.clear();
        return min(solve(root, 1, 0), solve(root, 0, 0));
    }
};


// APPROACH 2: Greedy-DFS
// Read this explanation: https://leetcode.com/problems/binary-tree-cameras/discuss/211180/JavaC%2B%2BPython-Greedy-DFS

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
    int res = 0;
public:
    int minCameraCover(TreeNode* root) {
        return (dfs(root) < 1 ? 1 : 0) + res;
    }

    int dfs(TreeNode* root) {
        if (!root) return 2;
        int left = dfs(root->left), right = dfs(root->right);
        if (left == 0 || right == 0) {
            res++;
            return 1;
        }
        return left == 1 || right == 1 ? 2 : 0;
    }
};