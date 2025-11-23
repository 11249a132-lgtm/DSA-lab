/* Aim:
To implement a stack using a linked list in C and perform basic stack operations such as push, pop, and display, using dynamic memory allocation and pointer manipulation.*/

#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list stack implementation
struct Node
{
    int data;              // Value stored in node
    struct Node *next;     // Pointer to next node (below it in stack)
};

// Function to create a new node and return its address
struct Node *CreateNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    // Check memory allocation
    if (!newNode)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    newNode->data = data;   // Assign value
    newNode->next = NULL;   // Initially next is NULL
    return newNode;
}

// PUSH Operation: Insert at the top of stack
void push(struct Node **top, int data)
{
    struct Node *newElement = CreateNode(data);

    // New node will now point to previous top
    newElement->next = *top;

    // Update top to new node
    *top = newElement;

    printf("Node with data %d pushed successfully.\n", data);
}

// POP Operation: Remove the top element
void pop(struct Node **top)
{
    if (*top == NULL)
    {
        // Stack is empty
        printf("Stack is empty/underflow, pop operation can't be performed.\n");
        return;
    }

    // Temporary pointer to remove node
    struct Node *temp = *top;

    // Move top to next node
    *top = temp->next;

    printf("Element %d popped from stack.\n", temp->data);

    // Free memory of removed node
    free(temp);
}

// Display all elements from top to bottom
void DisplayStack(struct Node *top)
{
    if (top == NULL)
    {
        printf("Stack is empty.\n");
        return;
    }

    struct Node *temp = top;

    printf("\nElements In Stack: [Top] ");
    
    // Traverse from top to bottom
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
}

// Main program with menu
int main()
{
    struct Node *top = NULL;    // Stack initially empty
    int choice, data;

    while (1)
    {
        printf("\n--- Stack Using Linked List Menu ---\n");
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
            scanf("%d", &data);
            push(&top, data);
            break;

        case 2:
            pop(&top);
            break;

        case 3:
            DisplayStack(top);
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
