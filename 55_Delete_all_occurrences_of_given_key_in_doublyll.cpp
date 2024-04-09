// Delete all occurrences of a given key in a doubly linked list gfg

//   https://youtu.be/Mh0NH_SD92k
// see video to understand

class Solution {
  public:
//   https://youtu.be/Mh0NH_SD92k
// see video to understand 
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // Write your code here
        Node *head=*head_ref;
        Node *temp=head;
        while(temp!=NULL){
            // Within the loop, check if the data stored in the current node (temp->data) is equal to the given key x.
            if(temp->data==x){
                // If the condition is true, it means the current node contains the key to be deleted.
// a. Check if temp is pointing to the head of the list. If so, update head to point to the next node.


                if(temp==head){
                    head=head->next;
                }
                Node *nextnode=temp->next;
                Node* prevnode=temp->prev;
            // b. Update the next and prev pointers of the neighboring nodes to skip temp.


                if(nextnode!=NULL){
                    nextnode->prev=prevnode;
                    
                }
                if(prevnode!=NULL){
                    prevnode->next=nextnode;
                }
                free(temp);
                temp=nextnode;
            }
            else{
                temp=temp->next;
            }
        }
      *head_ref = head;
    }
};
