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
    ListNode* merge(ListNode* t1, ListNode* t2){
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        while(t1!=NULL && t2!=NULL){
            if(t1->val<t2->val){
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
    
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode *slow = head, *fast = head, *temp = NULL;
        while(fast!=NULL){
            temp = slow;
            slow = slow->next;
            fast = fast->next;
            if(fast) fast = fast->next;
        }
        
        temp->next = NULL;
        head = sortList(head);
        slow = sortList(slow);
        head = merge(head, slow);
        
        return head;
    }
};