/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        Node* even = new Node(-1);
        Node* odd = new Node(-1);
        
        Node* t1 = even, * t2 = odd;
        
        Node* t = head;
        while(t!=NULL){
            if(t->data%2==0){
                t1->next = t;
                t1=t1->next;
            }
            else{
                t2->next = t;
                t2=t2->next;
            }
            t = t->next;
        }
        t1->next = odd->next;
        t2->next = NULL;
        return even->next;
    }
};
