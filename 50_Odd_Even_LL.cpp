// 328. Odd Even Linked List 
// https://youtu.be/qf6qp7GzD5Q 
// see video to understand 

class Solution {
public:
// https://youtu.be/qf6qp7GzD5Q
// see video to understand
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL||head->next==NULL){
        return head;
        }
         ListNode *even;
        ListNode* odd=head;
   
         even=head->next;
       
            ListNode* evenhead=head->next;
           while(even!=NULL && even->next!=NULL){
            odd->next=odd->next->next;
            even->next=even->next->next;
            odd=odd->next;
            even=even->next; 
        }
            odd->next=evenhead;
            return head;
    }
};
