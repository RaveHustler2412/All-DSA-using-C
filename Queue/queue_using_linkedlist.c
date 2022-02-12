#include <stdio.h>
#include <stdlib.h>

int opt, value;
struct Node
{
    int data;
    struct Node *next;
} *head = NULL;

void main()
{
    while (1)
    {
        printf("enter the option\n1.enqueue\n2.dequeue\n3.display\n4.exit\n");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
        {
            printf("enter the value ");
            scanf("%d", &value);
            enqueue(value);
            break;
        }
        case 2:
        {
            dequeue();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
            exit(0);
            break;

        default:
            break;
        }
    }
}

int isNull()
{
    if (head == NULL)
        return 1;
    return 0;
}
void enqueue(value)
{
    struct Node *newNode = malloc(sizeof(struct Node *));
    newNode->data = value;
    struct Node *temp = head;

    if (isNull())
    {

        newNode->next = NULL;
        head = newNode;
    }
    else
    {

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = NULL;
    }
}
void dequeue()
{
    if (isNull())
        printf("queue is empty\n");
    else
    {
        head = head->next;
    }
}
void display()
{
    if (isNull())
        printf("queue is empty\n");
    else
    {
        struct Node *temp = head;
        while (temp != NULL)
        {
            printf("%d--", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
