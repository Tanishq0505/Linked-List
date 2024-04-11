// Creating a simple nodes,inserting at begin ,end, middle in C(Doubly L.L)   

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
struct node *insertAtFirst(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    ptr->next = head;
    head->prev = ptr;
    head = ptr;
    return head;
}
struct node *insertAtIndex(struct node *head, int data, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    int i = 1;

    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next->prev = ptr;
    p->next = ptr;
    ptr->prev = p;
    return head;
}
struct node *insertAtEnd(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->prev = p;
    ptr->next = NULL;

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
    head = insertAtFirst(head, 5);
    printf("Inserting at beginnning in L.L\n\n");
    linkedListTraversal(head);
    // // indexing start from 0
    head = insertAtIndex(head, 6, 2);
    printf("Inserting in middle in L.L\n\n");
    linkedListTraversal(head);
    head = insertAtEnd(head, 7);
    printf("Inserting at end  in L.L\n\n");
    linkedListTraversal(head);

    return 0;
}
