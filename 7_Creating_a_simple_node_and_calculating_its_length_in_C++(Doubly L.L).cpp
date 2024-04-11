 Creating a simple node and calculating its length in C++(Doubly L.L) Explain in copy also 
#include <iostream>
#include <map>
using namespace std;
// https://youtu.be/q8gdBn9RPeI
// To understand see Lec44 from 59 min
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};
void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
// gives length of Linked List
int getLength(Node *head)
{
    int len = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    return len;
}
int main()
{ // created a new node
    Node *node1 = new Node(10);
    // head pointed to node1
    Node *head = node1;

    print(head);
    cout << getLength(head) << endl;
}
