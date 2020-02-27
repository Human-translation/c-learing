class Solution {
public:
    Node* flatten(Node* head) {
        Node* ptr = head;
        Node* begin = head;
        while(ptr != NULL){
            Node* star = NULL;
            if(ptr -> child != NULL)
                star = flatten(ptr -> child);
            ptr = ptr -> next;
            if(star != NULL){
                begin -> next = star;
                star -> prev = begin;
                begin -> child = NULL;
                while(begin->next != NULL)
                    begin = begin -> next;
                if(ptr != NULL){
                    begin->next = ptr;
                    ptr -> prev = begin; 
                }
            }
            begin = ptr;
        }
        return head;
    }
};