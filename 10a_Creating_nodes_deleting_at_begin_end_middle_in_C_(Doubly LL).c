// Creating a simple nodes ,deleting at begin ,end,middle in C(Doubly L.L) 
// creation of LL
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
// traversal time complexity is O(n)
void linkedListTraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// // Case 1: Deleting the first element from the linked list
struct node *deleteFirst(struct node *head)
{
    struct node *ptr = head;
    if (head == 0)
    {
        printf("List is empty");
    }
    else
    {
        ptr = head;
        head = ptr->next;
        head->prev = 0;
        free(ptr);
    }
    return head;
}
// Case 2 : Deleting the element at a given index from the linked list
struct node *deleteAtIndex(struct node *head, int index)
{
    struct node *p = head;
    struct node *q = head->next;
    for (int i = 1; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    q->prev = NULL;
    q->next->prev = p;
    free(q);
    return head;
}
// // Case 3: Deleting the last element
struct node *deleteAtLast(struct node *head)
{
    if (head == 0)
    {
        printf("List is empty");
    }
    else
    {
        struct node *p = head;
        struct node *q = head->next;

        while (q->next != NULL)
        {
            p = p->next;
            q = q->next;
        }

        p->next = NULL;
        q->prev = NULL;
        free(q);
    }
    return head;
}
int main()
{
    int n;
    printf("Enter the total no of nodes ");
    scanf("%d", &n);
    struct node *head, *newnode, *temp;
    head = 0;
    for (int i = 1; i <= n; i++)

    {

        newnode = (struct node *)malloc(sizeof(4));
        printf("Enter data ");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        newnode->prev = 0;
        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }

    linkedListTraversal(head);
    head = deleteFirst(head);
    printf("L.L after deletion of 1st element\n");
    linkedListTraversal(head);
    // // indexing is from 1
    head = deleteAtIndex(head, 2);
    printf("L.L after deletion at index element\n");
    linkedListTraversal(head);
    head = deleteAtLast(head);
    printf("L.L after deletion of last element\n");
    linkedListTraversal(head);
    return 0;
}
