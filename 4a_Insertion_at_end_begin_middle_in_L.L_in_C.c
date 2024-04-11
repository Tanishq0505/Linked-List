// Insertion at end ,begin ,middle in L.L in C. (Singly L.L) Explain in copy also 

#include <stdio.h>
#include <stdlib.h>
// https://youtu.be/ewCc7O2K5SM?list=PLu0W_9lII9ahIappRPN0MCAgtOu3lQjQi
// https://youtu.be/_PuIzVqJJbA?list=PLu0W_9lII9ahIappRPN0MCAgtOu3lQjQi
// see both the video to undersatnd better
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
struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = head;
    head = ptr;
    return head;
}
struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;

    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
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
    head->data = 1;
    head->next = second;

    // Link second and third nodes
    second->data = 2;
    second->next = third;

    // Link third and fourth nodes
    third->data = 3;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 4;
    fourth->next = NULL;
    printf("Creating a L.L\n\n");
    linkedListTraversal(head);

    head = insertAtFirst(head, 5);
    printf("Inserting at beginnning in L.L\n\n");
    linkedListTraversal(head);
    // indexing start from 0
    head = insertAtIndex(head, 6, 2);
    printf("Inserting in middle in L.L\n\n");
    linkedListTraversal(head);
    head = insertAtEnd(head, 7);
    printf("Inserting at end  in L.L\n\n");
    linkedListTraversal(head);
    return 0;
}
