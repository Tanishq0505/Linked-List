 // Creating a simple nodes and insert at begin,end,middle in C( Circular L.L) Explain in copy 

// explain in copy no video to understand 
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
struct node *addBegin(struct node *head, int data)
{
    // Creating a node dynamically.
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        // Assigning the data.
        temp->data = data;
        head = temp;
        // Note : list was empty. We link single node
        // to itself.
        temp->next = head;
    }
    else
    {
        struct node *last = head;
        while (last->next != head)
        {
            last = last->next;
        }
        // Assigning the data.
        temp->data = data;

        // Adjusting the links.
        temp->next = last->next;
        last->next = temp;
        head = temp;
        return head;
    }
}
struct node *addEnd(struct node *head, int data)
{
    // Creating a node dynamically.
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        temp->data = data;
        head = temp;
        // Note : list was empty. We link single node
        // to itself.
        temp->next = head;
    }
    else
    {
        struct node *last = head;
        while (last->next != head)
        {
            last = last->next;
        }
        // Assigning the data.
        temp->data = data;

        // Adjusting the links.
        temp->next = last->next;
        last->next = temp;
        last = temp;

        return head;
    }
}
struct node *addAfter(struct node *head, int data, int pos)
{
    if (head == NULL)
        return NULL;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    struct node *p, *q;
    p = head;
    q = head->next;
    int i = 1;
    while (i < pos)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = temp;
    temp->next = q;
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
    printf("LL before insrtion\n");
    linkedListTraversal(head);
    head = addBegin(head, 5);
    head = addBegin(head, 99);
    printf("LL after insrtion at begin \n");
    linkedListTraversal(head);
    head = addEnd(head, 72);
    head = addEnd(head, 49);
    printf("LL after insrtion at end \n");
    linkedListTraversal(head);
    head = addAfter(head, 30, 1);
    head = addAfter(head, 10, 2);
    printf("LL after insrtion at middle \n");
    linkedListTraversal(head);
    return 0;
}
