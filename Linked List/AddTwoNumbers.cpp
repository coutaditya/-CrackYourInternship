// In this question, the ll are given to store numbers in reverse order.
// If not, reverse the linked lists

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = new ListNode(0);
        ListNode* t = head;
        ListNode *t1 = l1, *t2 = l2;
        
        while(t1!=NULL && t2!=NULL){
            int d = t1->val + t2->val + carry;
            
            t1 = t1->next;
            t2 = t2->next;
            
            t->next = new ListNode(d%10);
            t=t->next;
            carry = d/10;
        }
        
        while(t1!=NULL){
            int d = t1->val + carry;
            
            t1 = t1->next;
            
            t->next = new ListNode(d%10);
            t=t->next;
            carry = d/10;
        }
        
        while(t2!=NULL){
            int d = t2->val + carry;
            
            t2 = t2->next;
            
            t->next = new ListNode(d%10);
            t=t->next;
            carry = d/10;
        }
        
        if(carry!=0){
            t->next = new ListNode(carry);
        }
        
        return head->next;
    }
};