// Given a linked list of 0s, 1s and 2s, sort it.
 // gfg
// https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1
class Solution
{
    // https://youtu.be/ogmBt6f9hw8?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA
// see lec 49 from 8min approach 2
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    
    void insertTail(Node *&tail, Node *curr)
{
    // new node create
    
    tail->next = curr;
    tail = curr;
}
    Node* segregate(Node *head) {
        
        // Add code here
        Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;
    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;
    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    Node *curr = head;

    // create separate list 0s, 1s and 2s
    while (curr != NULL)
    {

        int value = curr->data;

        if (value == 0)
        {
            insertTail(zeroTail, curr);
        }
        else if (value == 1)
        {
            insertTail(oneTail, curr);
        }
        else if (value == 2)
        {
            insertTail(twoTail, curr);
        }
        curr = curr->next;
    }

    // merge 3 sublist

    // 1s list not empty
    if (oneHead->next != NULL)
    {
        zeroTail->next = oneHead->next;
    }
    else
    {
        // 1s list -> empty
        zeroTail->next = twoHead->next;
    }

    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    // setup head
    head = zeroHead->next;

    // delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
    }
};
