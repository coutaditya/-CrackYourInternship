// Make two pointers and store lesser nodes in one and greater nodes in another

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
    ListNode* partition(ListNode* head, int x) {
        ListNode* less = new ListNode(-1);
        ListNode* gre = new ListNode(-1);
        
        ListNode *t1 = less, *t2 = gre;
        
        ListNode* temp = head;
        while(temp!=NULL){
            if(temp->val<x){
                t1->next = temp;
                temp = temp->next;
                t1 = t1->next;
            }
            else{
                t2->next = temp;
                temp = temp->next;
                t2 = t2->next;
            }
        }
        
        t1->next = gre->next;
        t2->next = NULL;
        head = less->next;
        return head;
    }
};