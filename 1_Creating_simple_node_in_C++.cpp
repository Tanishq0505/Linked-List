// Creating a simple node in C++ ( Singly L.L) Explain in copy also 

#include <iostream>
#include <map>
using namespace std;
// https://youtu.be/q8gdBn9RPeI
// To understand better see Lec44 from 7min
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
int main()
{

    // created a new node
    Node *node1 = new Node(10);
    cout << node1->data << endl;
    cout << node1->next << endl;
}
