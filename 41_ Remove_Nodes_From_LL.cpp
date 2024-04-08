//  2487. Remove Nodes From Linked List (Leet code) 

// https://youtu.be/cI3P6L6xgpY 
// see video to understand 

class Solution {
public:
// https://youtu.be/cI3P6L6xgpY
// see video to understand 
ListNode* reverse(ListNode* &head){
    ListNode* prev = NULL;
    ListNode* curr = head;
    while(curr!=NULL){
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}
    ListNode* removeNodes(ListNode* head) {
        head=reverse(head);
        ListNode* curr=head;
        int ma=head->val;
        ListNode*prev=head;
        head=head->next;
        while(head){
            if(head->val>=ma){
            ma=head->val;
            prev=head;
            head=head->next;

            }
            else
            {
                prev->next=head->next;
                head=prev->next;
            }
        }
        head=reverse(curr);
        return  head;
    }
        
    
};
