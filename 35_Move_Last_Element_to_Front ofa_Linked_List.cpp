// Move Last Element to Front of a Linked List (GFG)

// See copy& code  to understand

class Solution{
public:
// see copy and code to understand
   ListNode *moveToFront(ListNode *head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* q=head;
        ListNode* r= NULL;
        
        while (q->next!=NULL){
            r=q;
            q=q->next;
        }
        r->next=NULL;
        q->next=head;
        head=q;
        
  return head;}
};
