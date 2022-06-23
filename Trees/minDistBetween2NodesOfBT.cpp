

class Solution{
    int ans;
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int dfs(Node* root, int a, int b){
        if(root==NULL) return 0;
        
        int l = dfs(root->left, a, b);
        int r = dfs(root->right, a, b);
        
        if(root->data==a || root->data==b){
            if(l!=0){
                ans = l;
                return l;   
            }
            else if(r!=0){
                ans = r;
                return r;
            }
            else return 1;
        }
        
        if(l==0 && r==0) return 0;
        if(l==0) return r+1;
        if(r==0) return l+1;
        
        if(l!=0 && r!=0){
            ans = l+r;
            return l+r;
        }
        
    }
    
    int findDist(Node* root, int a, int b) {
        if(a==b) return 0;
        ans = 0;
        dfs(root, a, b);
        
        return ans;
    }
};