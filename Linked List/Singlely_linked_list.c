#include <stdio.h>
#include <stdlib.h>

int opt, value, pos;
struct Node
{
    int data;
    struct Node *next;
} *head = NULL;
void main()
{

    while (1)
    {
        printf("\nenter the choice\n1.insertionAtBeg\n2.insertionAtEnd\n3.deletionAtBeg\n4.deletionAtEnd\n5.InsertPos\n6.DeletePos\n7.Update\n8.Display\n9.Traverse\n10.Search\n");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
        {
            printf("enter the value ");
            scanf("%d", &value);
            insertionAtBeg(value);
            break;
        }
        case 2:
        {
            printf("enter the value");
            scanf("%d", &value);
            insertionAtEnd(value);
            break;
        }
        case 3:
            deletionAtBeg();
            break;
        case 4:
            deletionAtEnd();
            break;

        case 5:
        {
            printf("enter the position to be inserted\nenter the value ");
            scanf("%d %d", &pos, &value);
            InsertPos(pos, value);
            break;
        }

        case 6:
        {
            printf("enter the position to be deleted");
            scanf("%d", &pos);
            DeletePos(pos);
            break;
        }
        case 7:
        {
            printf("enter the position to be updated\nenter the value ");
            scanf("%d %d", &pos, &value);
            update(pos, value);
            break;
        }
        case 8:
            display();
            break;
        case 9:
            traverse(head);
            break;
        case 10:
        {
            if (isNull())
            {
                printf("List is empty\n");
            }
            else
            {

                if (search())
                    printf("Data is Present\n");
                else
                {
                    printf("Data not found\n");
                }
            }

            break;
        }

        default:
            break;
        }
    }
}

int isNull()
{
    if (head == NULL)
    {
        return 1;
    }
    return 0;
}
int traverse(struct Node *temp)
{
    if (isNull())
    {
        printf("List is empty\n");
    }
    else
    {

        if (temp->next != NULL)
        {
            traverse(temp->next);
        }
        printf("%d--", temp->data);
    }
}

int search()
{

    printf("enter the value to be searched ");
    scanf("%d", &value);

    struct Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void insertionAtBeg(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (isNull())
    {

        newNode->next = NULL;
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}
void insertionAtEnd(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (isNull())
    {
        newNode->next = NULL;
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = NULL;
    }
}
void deletionAtBeg()
{
    if (isNull())
    {
        printf("List is empty\n");
    }
    else
    {
        head = head->next;
    }
}
void deletionAtEnd()
{
    struct Node *temp = head;
    if (isNull())
    {
        printf("list is empty\n");
    }
    else
    {
        if (temp->next == NULL)
        {
            head = NULL;
        }
        else
        {

            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = NULL;
        }
    }
}

void InsertPos(int pos, int value)
{
    struct Node *temp = head;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (isNull())
    {
        printf("Insert the value first\n");
    }
    else
    {
        if (pos == 1)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {

            for (int i = 1; i < pos - 1; i++)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}
void DeletePos(int pos)
{
    struct Node *temp = head;
    if (isNull())
    {
        printf("List is empty");
    }
    else
    {
        if (pos == 1)
        {
            head = head->next;
        }
        else
        {
            for (int i = 1; i < pos - 1; i++)
            {
                temp = temp->next;
            }
            temp->next = temp->next->next;
        }
    }
}

void update(int pos, int value)
{
    struct Node *temp = head;
    if (isNull())
    {
        printf("list is empty\n");
    }
    else
    {

        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }
        temp->data = value;
    }
}
void display()
{
    struct Node *temp = head;

    if (isNull())
    {
        printf("list is empty\n");
    }
    else
    {

        while (temp != NULL)
        {
            printf("%d--", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}