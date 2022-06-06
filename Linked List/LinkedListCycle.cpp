/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// The Floyd's Algorithm for cycle detection

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL) return false;
        
        ListNode* slow = head->next;
        if(slow==NULL) return false;
        
        ListNode* fast = slow->next;
        
        while(slow!=fast && fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast = fast->next->next;
        }
        
        return (slow==fast);
        
    }
};