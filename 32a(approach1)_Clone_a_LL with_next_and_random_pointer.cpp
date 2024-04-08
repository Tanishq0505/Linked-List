//  Clone a linked list with next and random pointer 
// GFG question 
// This question is not done on vs see directly from (GFG) 
// Approach 2 

// https://youtu.be/83mPr0i56Gg?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA 
// lec 52 see from starting approach 2 

class Solution
{
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
    Node *copyList(Node *head)
    {
        //Write your code here
         //step 1: Create a Clone List
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        while(temp != NULL) {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp -> next;
        }
         //step 2: creating map:
        Node* cloneNode=cloneHead;
        Node* originalNode=head;
        unordered_map<Node* ,Node*> m;
           while( originalNode!= NULL){
            m[originalNode]=cloneNode;
             originalNode= originalNode->next;
             cloneNode=cloneNode->next;
        }
         //cloning the random pointer:
         cloneNode=cloneHead;
          originalNode=head;
          while(originalNode != NULL){
            cloneNode->arb=m[originalNode->arb];
             originalNode= originalNode->next;
             cloneNode=cloneNode->next;
        }
        return cloneHead;
    }

};
