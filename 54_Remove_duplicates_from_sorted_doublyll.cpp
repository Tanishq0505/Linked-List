//  Remove duplicates from a sorted doubly linked list (GFG)
//    // see code and do dry run to understand

class Solution
{
    // see code and do dry run to understand 
public:

    Node * removeDuplicates(struct Node *head)
    {
        // Your code here
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        Node* curr=head->next;
        Node* prevN=head;
        
        while(curr->next!=NULL){
            
            if(curr->data==prevN->data){
                
                curr->next->prev=prevN;
                prevN->next=curr->next;
                
            }
            else{
                prevN=prevN->next;
            }
            curr=curr->next;
        }
        
        if(curr->data==prevN->data){
            
            prevN->next=NULL;
        }
        return head;
    }

};
