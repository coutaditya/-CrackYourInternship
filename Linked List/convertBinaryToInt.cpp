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

// TC: O(n) single pass recursive solution

class Solution {
public:
    int solve(ListNode* node, int &pow){
        if(node==NULL){
            return 0;
        }
        
        int ans = solve(node->next, pow)+(node->val*pow);
        pow*=2;
        
        return ans;
    }
    
    int getDecimalValue(ListNode* head) {
        int pow = 1;
        return solve(head, pow);
    }
};