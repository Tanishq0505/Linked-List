// Input:
// N = 3
// value[] = {1,2,1}
// Output: 1
// Explanation: The given linked list is
// 1 2 1 , which is a palindrome and
// Hence, the output is 1.

#include <iostream>
#include <map>
#include <vector>
#include <array>
using namespace std;
// https : // youtu.be/aD7mBVnKFEU?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA
// To understand see Lec50 from starting approach 1
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
bool ch(vector<int> arr)
{
    int n = arr.size();
    int a = 0;
    int e = n - 1;
    while (a <= e)
    {
        if (arr[a] != arr[e])
            return false;
        else
        {
            a++;
            e--;
        }
    }
    return true;
}

void isPalindrome(Node *head)
{
    vector<int> arr;
    Node *temp = head;
    while (temp != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    if (ch(arr) == true)
    {
        cout << "Palindrome";
    }
    else
    {
        cout << "Not Palindrome";
    }
    // return ch(arr);
}
int main()
{

    // created a new node
    Node *node1 = new Node(1);
    // head pointed to node1
    Node *head = node1;
    // tail pointed to node1
    Node *tail = node1;

    insertAtTail(tail, 2);

    insertAtTail(tail, 1);

    // insertAtPosition(tail, head, 3, 22);
    print(head);
    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;
    isPalindrome(head);
}
