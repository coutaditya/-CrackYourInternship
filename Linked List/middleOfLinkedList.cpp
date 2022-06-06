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

// O(n) solution single pass (use 2 pointers)

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head==NULL) return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast!=NULL){
            slow = slow->next;
            fast = fast->next;
            if(fast!=NULL){
                fast = fast->next;
            }
        }
        
        return slow;
    }
};