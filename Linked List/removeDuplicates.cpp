// Note about freeing memory:
// We need to free memory when we delete a node. But don't use the |delete node;| construct on an interview without discussing it with the interviewer. 
// A list node can be allocated in many different ways and we can use delete node; only if we are sure that the nodes were allocated with new TreeNode(...);.

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        
        while(temp!=NULL){
            if(temp->next!=NULL && temp->val==temp->next->val){
                // ListNode * del = temp->next;
                temp->next = temp->next->next;
                // delete del;
            }
            else{ 
                temp=temp->next;
            }
        }
        
        return head;
    }
};
