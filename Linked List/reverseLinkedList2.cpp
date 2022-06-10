// Pretty Straightforward O(n) solution

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        bool first = false;
        
        ListNode* s = head, *e = head;
        left--;
        left--;
        if(left==-1) first=true;
        right--;
        while(!first && left--){
            s=s->next;
            e=e->next;
            right--;
        }
        
        while(right--){
            e=e->next;
        }
        
        ListNode* cur = s->next, * prev = e->next, * nxt = cur->next;
        if(first){
            cur = head;
            nxt = head->next;
        }
        
        while(nxt!=e->next){
            cur->next = prev;
            prev = cur;
            cur = nxt;
            nxt = nxt->next;
        }
        
        cur->next = prev;
        
        if(first) head = cur;
        else{
            s->next = cur;
        }
        
        return head;
    }
};