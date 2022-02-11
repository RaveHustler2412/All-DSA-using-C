#include <stdio.h>
#include <stdlib.h>

int opt, value;
struct Node
{
    int data;
    struct Node *next;
} *top = NULL;

void main()
{

    while (1)
    {
        printf("enter the option\n1.push\n2.pop\n3.display\n4.exit\n");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
        {
            printf("enter the value");
            scanf("%d", &value);
            push(value);
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            exit(0);
            break;
        }

        default:
            break;
        }
    }
}
int isNull()
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}

void push(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (isNull())
    {
        newNode->next = NULL;
        top = newNode;
    }
    else
    {
        newNode->next = top;
        top = newNode;
    }
}
void pop()
{
    if (top->next == NULL)
    {
        top = NULL;
    }
    else
    {
        top = top->next;
    }
}
void display()
{
    if (isNull())
    {
        printf("stack is empty\n");
    }
    else
    {
        struct Node *temp = top;
        while (temp->next != NULL)
        {
            printf("%d--", temp->data);
            temp = temp->next;
        }
        printf("%d\n", temp->data);
    }
}