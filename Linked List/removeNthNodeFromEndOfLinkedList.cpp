// TC: O(n) single pass solution SC: O(1)

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp = head;
        while(n--){
            temp = temp->next;
        }
        
        if(temp==NULL){
            ListNode* t = head;
            head=head->next;
            delete t;
        }
        else{
            ListNode* t = head;
            while(temp->next!=NULL){
                t = t->next;
                temp = temp->next;
            }
            ListNode* t1 = t->next;
            t->next = t->next->next;
            delete t1;
        }
        return head;
    }
};