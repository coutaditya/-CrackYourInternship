// We will insert the new nodes at alternate positions in the original ll
// Then during second traversal, we will set the random pointer for each new node
// Then in the third pass, we will seperate the two linked lists

// TC: O(3*n)  SC: O(1)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return head;
        
        Node* temp = head;
        while(temp!=NULL){
            Node* d = new Node(temp->val);
            d->next = temp->next;
            temp->next = d;
            temp = d->next;
        }
        
        temp = head;
        while(temp!=NULL){
            Node* d = temp->next;
            Node* t = temp->random;
            if(t!=NULL){
                d->random = t->next;
            }
            else{
                d->random = t;
            }
            
            temp = d->next;
        }
        
        temp = head;
        Node* head_new = head->next;
        while(temp->next->next!=NULL){
            Node* d = temp->next;
            temp->next = d->next;
            temp = temp->next;
            d->next = temp->next;
        }
        temp->next = NULL;
        
        return head_new;
    }
};