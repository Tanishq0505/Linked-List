// Deletion in L.L in C . (Singly L.L) Explain in copy also 

#include <stdio.h>
#include <stdlib.h>
// https://youtu.be/UQIJNobtzVY?list=PLu0W_9lII9ahIappRPN0MCAgtOu3lQjQi
// https : // youtu.be/R_7qJzAWrMg?list=PLu0W_9lII9ahIappRPN0MCAgtOu3lQjQi
// see both video to understand
struct Node
{
    int data;
    struct Node *next;
};
// traversal time complexity is O(n)
void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
// Case 1: Deleting the first element from the linked list
struct Node *deleteFirst(struct Node *head)
{
    struct Node *ptr = head;
    head = ptr->next;
    free(ptr);
    return head;
}
// Case 2 : Deleting the element at a given index from the linked list
struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);
    return head;
}
// Case 3: Deleting the last element
struct Node *deleteAtLast(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);
    return head;
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 11;
    second->next = third;

    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 66;
    fourth->next = NULL;

    linkedListTraversal(head);
    head = deleteFirst(head);
    printf("L.L after deletion of 1st element\n");
    linkedListTraversal(head);
    // indexing is from 0
    head = deleteAtIndex(head, 1);
    printf("L.L after deletion at index element\n");
    linkedListTraversal(head);
    head = deleteAtLast(head);
    printf("L.L after deletion of last element\n");
    linkedListTraversal(head);
    return 0;
}
