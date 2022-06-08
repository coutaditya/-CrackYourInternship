// We will copy the value of the next node to the current node and change link of the current node.
// Since it is given that the node won't be a tail node, we will encounter no difficulties

/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}*head;
*/


class Solution
{
    public:
    //Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del)
    {
        del->data = del->next->data;
        del->next = del->next->next;
    }

};