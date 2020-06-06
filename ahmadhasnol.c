#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}
node;

//The two functions, one is to make a linked list, the other is to see the final list
node *createlinkedlist(int n);
void displaylist(node *head1, node *head2);


//n is the number of items in each respective list
int n1 = 0;
int n2 = 0;


//Main function
int main(void)
{
    //Making the two lists
    node *head1 = NULL;
    node *head2 = NULL;
    printf("Number of nodes of list 1: ");
    scanf("%i", &n1);
    printf("Number of nodes of list 2: ");
    scanf("%i", &n2);
    head1 = createlinkedlist(n1);
    head2 = createlinkedlist(n2);
    displaylist(head1, head2);
    return 0;
}

node *createlinkedlist(int n)
{
    int i = 0;
    node *head = NULL;
    node *temp = NULL;
    //node p is the pointer to the current selected item in the linked list
    node *p = NULL;

    for (i = 0; i < n; i++)
    {
        temp = malloc(sizeof(node));
        printf("Integer %i: ", i + 1);
        scanf("%i", &(temp->data));
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            p = head;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = temp;

        }
    }
    return head;
}

void displaylist (node *head1, node *head2)
{
    node *p1 = head1;
    node *p2 = head2;

    //If n1 and n2 are equal (same number of items in both lists)
    while (p1 != NULL && p2 != NULL)
    {
            if ((p1->data) > (p2->data))
            {
                printf("%i %i ", p1->data, p2->data);
            }
            else if ((p1->data) <= (p2->data))
            {
                printf("%i %i ", p2->data, p1->data);
            }

            p1 = p1->next;
            p2 = p2->next;

    }
    //If there is one more item in list 1
    if (p1 != NULL)
    {
        printf("%i", p1->data);
    }

    //If there is one more item in list 2
    if (p2 != NULL)
    {
        printf("%i", p2->data);
    }

    printf("\n");
}
