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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL) return nullptr;
        ListNode* dummyHead=new ListNode(-1);
        ListNode* pre=head;
        ListNode* cur=head->next;
        dummyHead->next=head;
        while(cur!=nullptr) {
            if(cur->val<x){
                pre->next=cur->next;
                cur->next=dummyHead->next;
                dummyHead->next=cur;
                cur=pre->next;
            } 
            else {
                cur=cur->next;
                pre=pre->next;
            }
        }
        return dummyHead->next;
    }
};
