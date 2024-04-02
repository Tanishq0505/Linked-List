// Given the head of a singly linked list, reverse the list, and return the reversed list.
#include <iostream>
#include <map>
using namespace std;
// https://youtu.be/vqS1nVQdCJM?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA
// see  lec 45 this is approach 2
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};
void insertAtHead(Node *&head, int d)
{

    // new node create
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
void insertAtTail(Node *&tail, int d)
{
    // new node create
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node *&tail, Node *&head, int position, int d)
{

    // insert at Start
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // inserting at Last Position
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }

    // creating a node for d
    Node *nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;

    temp->next = nodeToInsert;
}
void print(Node *&head)
{

    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void reverse(Node *&head, Node *&curr, Node *&prev)
{
    // base case
    if (curr == NULL)
    {
        head = prev;
        return;
    }

    // solve the problem for the first node and then use recursion
    Node *forward = curr->next;
    reverse(head, forward, curr);
    curr->next = prev;
}
int main()
{

    // created a new node
    Node *node1 = new Node(10);
    // head pointed to node1
    Node *head = node1;
    // tail pointed to node1
    Node *tail = node1;
    print(head);
    insertAtTail(tail, 12);
    print(head);
    insertAtTail(tail, 13);
    print(head);
    insertAtPosition(tail, head, 3, 22);
    print(head);
    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;
    Node *prev = NULL;
    Node *curr = head;

    reverse(head, curr, prev);
    print(head);
}
