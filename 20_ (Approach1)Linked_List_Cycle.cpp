// 141. Linked List Cycle
// Given head, the head of a linked list, determine if the linked list has a cycle in it.

#include <iostream>
#include <map>
using namespace std;
// https://youtu.be/VxOFflTXlXo?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA
// To understand see Lec47 from starting Approach 1 detect cycle
class Node
{

public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
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
bool detectLoop(Node *head)
{

    if (head == NULL)
        return false;

    map<Node *, bool> visited;

    Node *temp = head;

    while (temp != NULL)
    {

        // cycle is present
        if (visited[temp] == true)
        {
            cout << "Cycle is present on element"
                 << " " << temp->data << endl;
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}
int main()
{

    // created a new node
    Node *node1 = new Node(10);
    // head pointed to node1
    Node *head = node1;
    // tail pointed to node1
    Node *tail = node1;
    insertAtTail(tail, 12);
    insertAtTail(tail, 15);
    insertAtPosition(tail, head, 4, 22);
    print(head);
    tail->next = head->next;

    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;
    if (detectLoop(head))
    {
        cout << " cycle is present" << endl;
    }
    else
    {
        cout << "cycle is not present " << endl;
    }
    return 0;
}
