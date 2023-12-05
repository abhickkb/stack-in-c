#include <stdio.h>
#include <stdlib.h>

#define size 100

struct Stack {
    int top;
    int arr[size];
};

struct Stack *ptr;

void push(int val) {
    if (ptr->top == size - 1) {
        printf("Stack is full. Cannot push %d\n", val);
    } else {
        ptr->top++;
        ptr->arr[ptr->top] = val;
        printf("%d pushed to the stack\n", val);
    }
}

int pop() {
    if (ptr->top == -1) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    } else {
        int popped = ptr->arr[ptr->top];
        ptr->top--;
        return popped;
    }
}

void display() {
    if (ptr->top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= ptr->top; i++) {
            printf("%d ", ptr->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    ptr = (struct Stack *)malloc(sizeof(struct Stack));
    ptr->top = -1;
    

    int val, choice;
    while (1) {
        printf("\n\n----------Main Menu Stack Using Array-------------\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element you want to push: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                printf("Popped element: %d\n", pop());
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("That is an invalid choice!\n");
        }
    }
    return 0;
}
