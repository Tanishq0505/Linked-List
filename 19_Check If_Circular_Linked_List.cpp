// Gfg
// Check If Circular Linked List
bool isCircular(Node *head)
{
    //  https://youtu.be/fi2vh0nQLi0?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA
// see from 22 MIN  LEC 46 Approach 1

   // Your code here
   if (head == NULL)
    {
        return true;
    }

    Node *temp = head->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }

    if (temp == head)
    {
        return true;
    }

    return false;
}
