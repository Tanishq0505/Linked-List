// 138. Copy List with Random Pointer
// leetcode

class Solution {
    // https://youtu.be/83mPr0i56Gg?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA 

// lec 52 see from starting approach 3 
    private:
    void insertAtTail(Node* &head, Node* &tail, int d) {
        Node* newNode = new Node(d);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail -> next = newNode;
            tail = newNode;
        }
    }
public:
    Node* copyRandomList(Node* head) {
          //step 1: Create a Clone List
        Node* clonehead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        while(temp != NULL) {
            insertAtTail(clonehead, cloneTail, temp->val);
            temp = temp -> next;
        }

        // step 2 cloneNode add in between original list
        Node* originalNode=head;
        Node* cloneNode=clonehead;

        while(originalNode!=NULL && cloneNode!=NULL){
            Node* next=originalNode->next;
            originalNode->next=cloneNode;
            originalNode=next;
            next=cloneNode->next;
            cloneNode->next=originalNode;
            cloneNode=next;
        }
        // step3: random pointer copy 
       temp=head;
        while(temp!=NULL){
            if(temp->next!=NULL){
                temp->next->random=temp->random?temp->random->next:temp->random; 
            }
            temp=temp->next->next;
        }
        // step4 revert changes done in step 2 
        originalNode=head;
        cloneNode=clonehead;
         while(originalNode!=NULL && cloneNode!=NULL){
             originalNode->next=cloneNode->next;
            originalNode=originalNode->next;
            if(originalNode!=NULL){
            cloneNode->next=originalNode->next;
            }
            cloneNode=cloneNode->next;
         }
        //  step5 return ans
        return clonehead;
    }
};
