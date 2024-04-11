// Creating a simple nodes in C(Doubly L.L)
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

    return 0;
}
