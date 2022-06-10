// TC: O(n) SC: O(1) iterative solution

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
        if(head == NULL || head->next==NULL) return head;
        ListNode* temp = head;
        ListNode* s = new ListNode(-1);
        s->next = head;
        head = s;
        
        while(temp!=NULL && temp->next!=NULL){
            bool dup = false;
            while(temp->next!=NULL && temp->val==temp->next->val){
                dup = true;
                ListNode* t = temp->next;
                temp->next = temp->next->next;
                delete t;
            }
            if(dup){
                ListNode* t = temp;
                temp = temp->next;
                s->next = temp;
                delete t;
            }
            else{
                s = s->next;
                temp = temp->next;
            }
        }
        
        head = head->next;
        return head;
    }
};