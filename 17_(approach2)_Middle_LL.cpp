// 876. Middle of the Linked List
// Leetcode
// https://youtu.be/vqS1nVQdCJM?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA 
// To understand see Lec45 from 43 min 

Node *middleNode(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    if (head->next->next == NULL)
        return head->next;

    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
        slow = slow->next;
    }
    cout << slow->data << " ";
    return slow;
}
