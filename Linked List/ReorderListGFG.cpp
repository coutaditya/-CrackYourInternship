Node* reverse(Node* head){
    if(head == NULL) return head;
    
    Node* prev = NULL, * cur = head, * nxt = head->next;
    while(cur!=NULL){
        cur->next = prev;
        prev = cur;
        cur = nxt;
        if(nxt) nxt = nxt->next;
    }
    
    head = prev;
    return head;
}

void reorderList(Node* head) {
    if(head==NULL || head->next==NULL){
        return;
    }
    
    Node *temp = NULL, *slow = head, *fast = head;
    
    while(fast!=NULL){
        temp = slow;
        slow = slow->next;
        fast = fast->next;
        if(fast) fast=fast->next;
    }
    
    temp->next = NULL;
    
    slow = reverse(slow);
    
    Node* t1 = head;
    Node* t2 = slow;
    
    
    fast = head;
    while(slow!=NULL){
        temp = fast->next;
        fast->next = slow;
        slow = slow->next;
        fast->next->next = temp;
        fast = temp;
    }  
}