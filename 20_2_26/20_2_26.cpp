class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> str;
        ListNode *head = root;
        int num = 0,yuwei = 0,chuwei = 0;
        while(head != NULL)
        {
            num++;
            head = head -> next;
        }
        chuwei = num / k;
        yuwei = num % k;
        head = root;
        for(int i=0;i<k;i++)
        {
            str.push_back(root);
            if(root == NULL)
                continue;
            for(int j=0;j<chuwei;j++)
            {
                if(j != 0)
                    head = head -> next;
                root = root -> next;
            }
            if(yuwei > 0)
            {
                root = root -> next;
                if(chuwei != 0)
                    head = head -> next;
                yuwei--;
            }
            head -> next = NULL;
            head = root; 
        }
        return str;
    }
};