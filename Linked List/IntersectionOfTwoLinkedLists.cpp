// We start from head of both lists, if we reach end of a list, we make it beginning of other. We do this (2 times max) till we get both pointers equal.
// TC: O(n)  SC: O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * t1 = headA;
        ListNode * t2 = headB;
        
        while(t1!=NULL && t2!=NULL){
            if(t1==t2) return t1;
            
            t1=t1->next;
            t2=t2->next;
        }
        
        if(t1==NULL){
            t1=headB;
        }
        else{
            t2=headA;
        }
        
        while(t1!=NULL && t2!=NULL){
            if(t1==t2) return t1;
            
            t1=t1->next;
            t2=t2->next;
        }
        
        if(t1==NULL){
            t1=headB;
        }
        else{
            t2=headA;
        }
        
        while(t1!=NULL && t2!=NULL){
            if(t1==t2) return t1;
            
            t1=t1->next;
            t2=t2->next;
        }
        
        return t1;
    }
};