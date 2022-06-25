// https://www.geeksforgeeks.org/largest-bst-binary-tree-set-2/
// We basically move in a bottom-up manner and for each node, we check if the largest node in the left subtree is smaller than node and
// smallest node in right subtree is greater than node and both subtrees are BSTs then we store the ans

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
 
/* Helper function that allocates a new
node with the given data and NULL left
and right pointers. */
struct Node* newNode(int data)
{
    struct Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
 
    return(node);
}
 
// Information to be returned by every
// node in bottom up traversal.
struct Info
{
    int sz; // Size of subtree
    int max; // Min value in subtree
    int min; // Max value in subtree
    int ans; // Size of largest BST which
    // is subtree of current node
    bool isBST; // If subtree is BST
};
 
// Returns Information about subtree. The
// Information also includes size of largest
// subtree which is a BST.
Info largestBSTBT(Node* root)
{
    // Base cases : When tree is empty or it has
    // one child.
    if (root == NULL)
        return {0, INT_MIN, INT_MAX, 0, true};
    if (root->left == NULL && root->right == NULL)
        return {1, root->data, root->data, 1, true};
 
    // Recur for left subtree and right subtrees
    Info l = largestBSTBT(root->left);
    Info r = largestBSTBT(root->right);
 
    // Create a return variable and initialize its
    // size.
    Info ret;
    ret.sz = (1 + l.sz + r.sz);
 
    // If whole tree rooted under current root is
    // BST.
    if (l.isBST && r.isBST && l.max < root->data &&
            r.min > root->data)
    {
        ret.min = min(l.min, min(r.min, root->data));
        ret.max = max(r.max, max(l.max, root->data));
 
        // Update answer for tree rooted under
        // current 'root'
        ret.ans = max(l.ans, r.ans) + 1;
        ret.isBST = true;
 
        return ret;
    }
 
    // If whole tree is not BST, return maximum
    // of left and right subtrees
    ret.ans = max(l.ans, r.ans);
    ret.isBST = false;
 
    return ret;
}