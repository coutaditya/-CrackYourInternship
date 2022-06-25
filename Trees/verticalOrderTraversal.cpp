// My Ghisa-Pita solution (involving extra space to store row and col of each node and the sorting it to get the answer)
// TC: O(nlog(n)) SC: O(n)

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

bool comp(vector<int> a, vector<int> b){
    if(a[1]==b[1]){
        if(a[0]==b[0]){
            return a[2]<b[2];
        }
        
        return a[0]<b[0];
    }
    
    return a[1]<b[1];
}

class Solution {
    vector<vector<int> > store;
public:
    void dfs(TreeNode* root, int row, int col){
        if(root==NULL) return;
        
        store.push_back({row, col, root->val});
        
        dfs(root->left, row+1, col-1);
        dfs(root->right, row+1, col+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int> > ans;
        if(root==NULL) return ans;
        store.clear();
        
        dfs(root, 0, 0);
        
        sort(store.begin(), store.end(), comp);
        int id = store[0][1];
        for(int i=0; i<store.size(); i++){
            vector<int> v;
            while(i<store.size() && store[i][1]==id){
                v.push_back(store[i][2]);
                i++;
            }
            ans.push_back(v);
            if(i!=store.size()){
                id = store[i][1];
            }
            i--;
        }
        return ans;
    }
};


// Optimised using map and multiset
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<int> > m;  // when iterate map, key is already the order of x-axis
        queue<pair<int, TreeNode*> > q; // for level traversal
        q.push(make_pair(0, root));  // root default x-axis is 0
        while(!q.empty()) {
            multiset<pair<int, int> > tmp;  // k: x-axis, v:val Already solved the case when the position is ths same
            int len=q.size();
            for(int i=0;i<len;++i) {
                auto p=q.front();q.pop();
                tmp.insert(make_pair(p.first, p.second->val));
                if (p.second->left) q.push(make_pair(p.first-1, p.second->left));
                if (p.second->right) q.push(make_pair(p.first+1, p.second->right));
            }

            for(auto p : tmp) m[p.first].push_back(p.second);
        }

        vector<vector<int> > res;
        for(auto kv : m) res.push_back(kv.second);
        return res;
    }
};