//  Split a Circular Linked List into two halves (GFG)
// https://www.geeksforgeeks.org/problems/split-a-circular-linked-list-into-two-halves/1
// see code &copy and do dry run to understand


void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // see code &copy and do dry run to understand
    // your code goes here
    Node *slow=head,*fast=head->next;
    while(fast!=head&&fast->next!=head){
        slow=slow->next;
       fast = fast -> next -> next; 
    }
    *head2_ref=slow->next;
    slow->next=head;
    fast=*head2_ref;
    while(fast->next!=head){
        fast=fast->next;
    }
    fast->next=*head2_ref;
    *head1_ref=head;
}
