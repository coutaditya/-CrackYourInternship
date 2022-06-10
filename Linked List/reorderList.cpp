// APPROACH 1: TC: O(n) SC: O(1)
// Reverse the second half of the ll, then change the pointers accordingly. 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next == NULL){
            return head;
        }
        
        ListNode *prev = NULL, *cur = head, *nxt = head->next;
        while(nxt!=NULL){
            cur->next = prev;
            prev = cur;
            cur = nxt;
            nxt = nxt->next;
        }
        cur->next = prev;
        
        return cur;
    }
    
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL) return;
        
        ListNode *slow = head, *fast = head;
        while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slow->next = reverse(slow->next);
        
        ListNode *temp = slow->next;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<"\n";
        
        fast = head;
        ListNode * mid = slow->next;
        slow = slow->next;
        bool odd = true;
        
        while(slow!=NULL){
            ListNode* t1 = fast->next, *t2 = slow->next;
            if(t1==mid){
                t1=NULL;
                odd = false;
            } 
            fast->next = slow;
            slow->next = t1;
            fast = t1;
            slow = t2;
        }
        
        if(odd){
            fast->next = NULL;
        }  
        
        return;
    }
};

// APPROACH 2: TC: O(n) SC: O(n)
// Use a stack to store all the nodes, then for the first (n/2) nodes, pick the top of stack and make it the next.

class Solution {
public:
    void reorderList(ListNode* head) {
        if ((!head) || (!head->next) || (!head->next->next)) return; // Edge cases
        
        stack<ListNode*> my_stack;
        ListNode* ptr = head;
        int size = 0;
        while (ptr != NULL) // Put all nodes in stack
        {
            my_stack.push(ptr);
            size++;
            ptr = ptr->next;
        }
        
        ListNode* pptr = head;
        for (int j=0; j<size/2; j++) // Between every two nodes insert the one in the top of the stack
        {
            ListNode *element = my_stack.top();
            my_stack.pop();
            element->next = pptr->next;
            pptr->next = element;
            pptr = pptr->next->next;
        }
        pptr->next = NULL;
    }
};