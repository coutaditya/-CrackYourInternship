/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

// APPROACH 1: traverse the ll and count no. of 0s, 1s and 2s
// then place 0s, 1s, and 2s in the ll
// TC: O(2n)  SC:O(1)

class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        Node* temp = head;
        
        int z = 0, o = 0, t = 0;
        
        while(temp!=NULL){
            if(temp->data==0) z++;
            if(temp->data == 1) o++;
            else t++;
            
            temp=temp->next;
        }
        
        temp = head;
        while(temp!=NULL){
            if(z!=0){
                temp->data = 0;
                z--;
            }
            else if(o!=0){
                temp->data = 1;
                o--;
            }
            else{
                temp->data = 2;
                t--;
            }
            
            temp=temp->next;
        }
        
        return head;
        
    }
};


// APPROACH 2:
// Maintan 3 ll, for 0, 1 and 2 and keep adding nodes to them as we traverse the ll
// Link all of them together
// TC: O(n)  SC: O(n)