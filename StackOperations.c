/* Aim:
To write a C program to implement a stack using a dynamic array and perform basic stack operations such as push, pop, and display, while checking overflow and underflow conditions.*/

#include <stdio.h>
#include <stdlib.h>

int top = -1;     // Top pointer initialized to -1 (Stack empty)
int size;         // Size of the stack (user input)
char *STACK;      // Dynamic array to store stack elements

/*
    FUNCTION: push
    PURPOSE : Insert (push) an element into the stack
*/
void push(char item)
{
    // Check for overflow condition
    if (top == (size - 1))
    {
        printf("Stack is already full, no additional push allowed - Overflow\n");
    }
    else
    {
        top = top + 1;      // Increment top
        STACK[top] = item;  // Insert element
    }
}

/*
    FUNCTION: pop
    PURPOSE : Remove (pop) the top element from the stack
*/
void pop()
{
    // Check for underflow condition
    if (top == -1)
    {
        printf("Stack is underflow\n");
    }
    else
    {
        char temp = STACK[top];  // Store top element
        top = top - 1;           // Decrement top pointer
        printf("Element popped: %c\n", temp);
    }
}

/*
    FUNCTION: DisplayStack
    PURPOSE : Display all stack elements from top to bottom
*/
void DisplayStack()
{
    if (top == -1)
    {
        printf("Stack is underflow\n");
        return;
    }

    printf("[Top]\n");
    for (int i = top; i >= 0; i--)
    {
        printf("%c\n", STACK[i]);
    }
}

/*
    MAIN FUNCTION
    Menu-driven program to perform stack operations
*/
int main()
{
    int choice;
    char data;

    printf("Enter size of stack: ");
    scanf("%d", &size);

    // Allocate memory dynamically for stack
    STACK = (char *)malloc(size * sizeof(char));

    while (1)
    {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to push: ");
            scanf(" %c", &data); // Space added to avoid newline input issue
            push(data);
            break;

        case 2:
            pop();
            break;

        case 3:
            DisplayStack();
            break;

        case 4:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
