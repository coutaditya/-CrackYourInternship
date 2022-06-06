// The idea is to create a 4 var and traverse the lists while making the links (see striver's video in case of problems)

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list2==NULL){
            return list1;
        }
        if(list1==NULL){
            return list2;
        }
        ListNode* list=NULL;
        ListNode* u=NULL;
        ListNode* un=NULL;
        ListNode* l=NULL;
        ListNode* ln=NULL;
        if(list1->val<list2->val){
            list=list1;
            l=list1;
            ln=l->next;
            u=list2;
            un=u->next;
        }
        else{
            list=list2;
            l=list2;
            ln=l->next;
            u=list1;
            un=u->next;
        }
        while(ln!=NULL && un!=NULL){
            if(ln->val<u->val){
                ln=ln->next;
                l=l->next;
            }
            else{
                l->next=u;
                u->next=ln;
                u=un;
                un=un->next;
                l=l->next;
            }
        }
        
        
        if(un==NULL){
            while(ln!=NULL && ln->val<u->val){
                l=ln;
                ln=ln->next;
            }
            l->next=u;
            u->next=ln;
            return list;
        }
        if(ln==NULL){
            l->next=u;
            return list;
        }
        return list;
    }
};