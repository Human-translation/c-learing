#include <iostream>
#include <string>

using namespace std;
/*
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        string s;
        int num = 0;
        
        while(head != NULL)
        {
            s += head -> val + '0';
            head = head -> next;
        }
        string::iterator it = s.begin();
        while(it < s.end())
        {
            num *= 2;
            if(*it == '1')
            {
                num += 1;
            }
            it++;
        }
        return num;
    }
};


class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* fast = head;
        ListNode* last = head;
        for(int i=0;i<k;i++)
            fast = fast -> next;
        while(fast != NULL)
        {
            fast = fast -> next;
            last = last -> next;
        }
        return last;
    }
};


class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        stack<int> stk;
        vector<int> num;
        while(head != NULL)
        {
            stk.push(head->val);
            head = head -> next;
        }
        while(stk.empty() == 0)
        {
            num.push_back(stk.top());
            stk.pop();
        }
        return num;
    }
};



class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* str = new ListNode(0);
        ListNode* head = str;
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val < l2->val)
            {
                head -> next = l1;
                head = head -> next;
                l1 = l1 -> next;
            }
            else
            {
                head -> next = l2;
                head = head -> next;
                l2 = l2 -> next;
            }
        }
        if(l1 != NULL)
        {
            head -> next = l1;
        }
        if(l2 != NULL)
        {
            head -> next = l2;
        }
        return str->next;
    }
};



class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL)
        {
            if(head->val == val)
            {
                head = head -> next;
                fast = head;
                slow = head;
                continue;
            }
            if(fast -> val == val)
            {
                slow -> next = fast -> next;
                fast = slow -> next;
                if(fast == NULL)
                    break;
                continue;
            }

            if(slow == fast)
                fast = fast->next;
            else 
            {
                fast = fast->next;
                slow = slow -> next;
            }
        }
        return head;
    }
};




class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* str = new ListNode(0);
        ListNode* wei = NULL;  
        while(head != NULL)
        {
            ListNode* arrow = head;
            head = head ->next;
            str -> next = arrow;
            arrow -> next = wei;
            wei = arrow;
        }
        return str->next;
    }
};


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* A=headA;
        ListNode* B=headB;
        stack<ListNode*> listA;
        stack<ListNode*> listB;
        ListNode* head = NULL;
        while(A != NULL)
        {
            listA.push(A);
            A = A->next;
        }
        while(B != NULL)
        {
            listB.push(B);
            B = B->next;
        }
        while(listA.empty()==0 && listB.empty()==0)
        {
            if(listA.top() == listB.top())
            {
                head = listA.top();
                listA.pop();
                listB.pop();
            }
            else
                break;
        }
        return head;
    }
};




class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* fast=head;
        ListNode* slow=head;
        if(head->val == val)
        {
            head = head -> next;
            return head;
        }
        while(fast->val != val)
        {
            if(slow == fast)
                fast = fast->next;
            else
            {
                fast = fast->next;
                slow = slow -> next;
            }
        }
        slow ->next = fast ->next;
        return head;
    }
};




*/