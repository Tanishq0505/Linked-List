// Intersection of two sorted Linked lists
// gfg

class Solution
{
    // see code and copy to understand 
    public:
    void insertAtTail(Node* &head,Node* &tail, int val) {
        
         Node* temp = new  Node(val);
        //empty list
        if(head == NULL) {
            head = temp;
            tail = temp;
            return;
        }
        else
        {
            tail -> next = temp;
            tail = temp;
        }
    }
    Node* findIntersection(Node* head1, Node* head2)
    {
        // code goes here.
        Node*temp1=head1;
        Node*temp2=head2;
        Node* anshead = NULL;
        Node* anstail = NULL;
        while(temp1!=NULL&&temp2!=NULL){
             if(temp1->data==temp2->data){
                 int digit=temp1->data;
        insertAtTail(anshead, anstail, digit);
         temp1=temp1->next;
        temp2=temp2->next;
             }
            
             
             else if(temp1->data<temp2->data){
             temp1=temp1->next;
             }
        else{
            temp2=temp2->next;
        }
        }
       
        return anshead;
    }
};
