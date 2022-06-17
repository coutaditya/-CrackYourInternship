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

// Brute Force Implementation, where I check the minimum out of all lists, and increment the pointer for the chosen node.

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        
        vector<ListNode*> t = lists;
        ListNode* temp = new ListNode(-1);
        ListNode* t1 = temp;
        
        bool allNull = false;
        
        while(!allNull){
            allNull = true;
            ListNode* s = new ListNode(INT_MAX);
            int id = -1;
            for(int i=0; i<k; i++){
                if(t[i]!=NULL && s->val>t[i]->val){
                    s = t[i];
                    id = i;
                    allNull = false;
                }
            }
            
            if(!allNull){
                t1->next = t[id];
                t[id]=t[id]->next;
                t1 = t1->next;
            }
        }
        
        return temp->next;
    }
};


// Optimised Implementation: We use a min-heap (with custom comparator) to store the heads of each list and chose the top of heap
// then we pop it and push the next node from that list into the heap if it is not null.

class Solution {
public:
    struct compare {
        bool operator()(const ListNode* l, const ListNode* r) {
            return l->val > r->val;
        }
    };
    
    ListNode *mergeKLists(vector<ListNode *> &lists) { //priority_queue
        priority_queue<ListNode *, vector<ListNode *>, compare> q;
        for(auto l : lists) {
            if(l)  q.push(l);
        }
        if(q.empty())  return NULL;

        ListNode* result = q.top();
        q.pop();
        if(result->next) q.push(result->next);
        ListNode* tail = result;            
        while(!q.empty()) {
            tail->next = q.top();
            q.pop();
            tail = tail->next;
            if(tail->next) q.push(tail->next);
        }
        return result;
    }
};