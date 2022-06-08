// Find the mid point first, then reverse the second half of the linked list and check val of nodes one by one after that

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
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode *prev = NULL, *cur = head, *nxt = head->next;
        
        while(nxt!=NULL){
            cur->next = prev;
            prev=cur;
            cur=nxt;
            nxt=nxt->next;
        }
        
        cur->next = prev;
        return cur;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        fast = slow;
        slow = slow->next;
        fast->next = NULL;
        fast = head;
        
        slow = reverse(slow);
        
        while(fast!=NULL && slow!=NULL){
            if(fast->val!=slow->val){
                return false;
            }
            fast = fast->next;
            slow = slow->next;
        }
        
        return true;
        
    }
};