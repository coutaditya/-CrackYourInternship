// TC: O(nlog(n))  SC: O(log(n))   (max log(n) variables created in the stack at a time during recursive calls)


/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* merge(Node* t1, Node* t2){
        Node* dummy = new Node(0);
        Node* temp = dummy;
        
        while(t1 && t2){
            if(t1->data<t2->data){
                temp->next = t1;
                t1=t1->next;
            }
            else{
                temp->next = t2;
                t2=t2->next;
            }
            temp = temp->next;
        }
        
        if(t1) temp->next = t1;
        if(t2) temp->next = t2;
        
        return dummy->next;
    }
    
    Node* mergeSort(Node* head) {
        if(head==NULL || head->next==NULL) return head;
        
        Node *temp = NULL, *slow = head, *fast = head;
        
        while(fast!=NULL){
            temp = slow;
            slow = slow->next;
            fast = fast->next;
            if(fast) fast = fast->next;
        }
        
        temp->next = NULL;
        head = mergeSort(head);
        slow = mergeSort(slow);
        
        head = merge(head, slow);
        
        return head;
    }
};