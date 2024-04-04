// explain in copy no video to understand
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

// traversal time complexity is O(n)
void linkedListTraversal(struct node *p)
{
    struct node *t = p;
    do
    {
        printf("Element: %d\n", t->data);
        t = t->next;
    } while (t != p);
}
// Case 1: Deleting the first element from the linked list
struct node *deleteFirst(struct node *head)
{
    if (head == NULL)
    {

        printf("NO node presnt\n");
    }
    else
    {

        struct node *last = head;
        while (last->next != head)
        {
            last = last->next;
        }
        struct node *ptr = head;
        head = ptr->next;
        last->next = head;
        free(ptr);
        return head;
    }
}
// Case 2 : Deleting the element at a given index from the linked list
struct node *deleteAtIndex(struct node *head, int index)
{
    if (head == NULL)
    {

        printf("NO node presnt\n");
    }
    else
    {
        struct node *p = head;
        struct node *q = head->next;
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
            q = q->next;
        }

        p->next = q->next;
        free(q);
        return head;
    }
}
// Case 3: Deleting the last element
struct node *deleteAtLast(struct node *head)
{
    if (head == NULL)
    {

        printf("NO node presnt\n");
    }
    else
    {
        struct node *p = head;
        struct node *q = head->next;
        while (q->next != head)
        {
            p = p->next;
            q = q->next;
        }

        p->next = head;
        free(q);
        return head;
    }
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
        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
            newnode->next = head;
        }
    }

    linkedListTraversal(head);
    head = deleteFirst(head);
    printf("L.L after deletion of 1st element\n");
    linkedListTraversal(head);
    // indexing is from 0
    head = deleteAtIndex(head, 2);
    printf("L.L after deletion at index element\n");
    linkedListTraversal(head);
    head = deleteAtLast(head);
    printf("L.L after deletion of last element\n");
    linkedListTraversal(head);
    return 0;
}
