#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int val)
{
    printf("Enter the value you want to insert: ");
    scanf("%d", &val);
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL)
    {
        printf("Memory allocation failed. Cannot push %d\n", val);
    }

    ptr->data = val;
    ptr->next = top;
    top = ptr;

    printf("%d The element is pushed.\n", val);
}

int pop()
{
    if (top == NULL)
    {
        printf("The stack is empty! Cannot pop.\n");
        return -1;
    }
    else
    {
        struct Node *p = top;
        int popped = p->data;
        top = p->next;
        free(p);
        return popped;
    }
}

void display()
{
    if (top == NULL)
    {
        printf("The stack is empty!\n");
    }
    else
    {
        printf("Now the elements are: ");
        struct Node *p = top;
        while (p != NULL)
        {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
}

int main()
{
    int val, choice;

    while (1)
    {
        printf("\n\n----Main Menu -----\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push(val);
            display();
            break;
        case 2:
            printf("%d is popped.\n", pop());
            display();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("The value is invalid!\n");
        }
    }

    return 0;
}
