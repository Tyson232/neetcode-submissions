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
    ListNode* reverseList(ListNode* head) {
        
        ListNode *i,*j,*k,*ans;
        i = head;
        if(!head) return nullptr;
        
        if(head->next){
            j = head->next;
        }
        else{
            return head;
        }
        if(j->next){
            k = j->next;
        }
        else{
            j->next = i;
            i->next=nullptr;
            return j;
        }
        head->next = nullptr;
        while(j){
            j->next = i;
            i = j;
            j = k;
            ans = j;
            if(k)k = k->next;

        }
        return i;
    }
};
