// Given a linked list of 0s, 1s and 2s, sort it. (gfg)

// https://youtu.be/ogmBt6f9hw8?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA
// see lec 49 from starting approach 1

void sort(Node *head)
{
    int n0 = 0, n1 = 0, n2 = 0; // The variables to store the frequency of 0s, 1s and 2s

    Node *curr = head; // Initializing the curr with head

    // Storing the count of 0,1 and 2 in the respective variables
    while (curr != NULL)
    {
        if (curr->data == 0)
        {
            n0++; // Increasing frequency of 0s
        }
        else if (curr->data == 1)
        {
            n1++; // Increasing frequency of 1s
        }
        else if (curr->data == 2)
        {
            n2++; // Increasing frequency of 2s
        }
        curr = curr->next; // Traversing the linked list till end
    }

    // Since we have to traverse from the head, we are reinitializing the value of curr with head

    curr = head;

    while (curr != NULL)
    {
        if (n0 > 0) // filling the list with 0, till n0 > 0
        {
            curr->data = 0; // changing value of node to 0
            curr = curr->next;
            n0--;
        }
        else if (n1 > 0) // filling the list with 1, till n2 > 0
        {
            curr->data = 1; // changing value of node to 1
            curr = curr->next;
            n1--;
        }
        else if (n2 > 0) // filling the list with 2, till n2 > 0
        {
            curr->data = 2; // changing value of node to 2
            curr = curr->next;
            n2--;
        }
    }
}
