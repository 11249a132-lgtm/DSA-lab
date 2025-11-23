/* Aim:
To write a C program to implement a Circular Queue using a Linked List and perform operations such as enqueue, dequeue, and display, while maintaining the circular linkage between the rear and front nodes.*/

#include <stdio.h>
#include <stdlib.h>

/*
    Node structure for Circular Queue using Linked List
*/
struct Node
{
    int data;
    struct Node *next; // Points to next node
};

struct Node *front = NULL; // Points to first node
struct Node *rear = NULL;  // Points to last node

/*
    FUNCTION: enqueue
    PURPOSE : Insert (add) an element at the rear of the circular queue
*/
void enqueue(int item)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    // Check memory allocation
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = item;

    // Case 1: Queue is empty
    if (front == NULL && rear == NULL)
    {
        front = rear = newNode;
        newNode->next = front; // Circular link
    }
    else
    {
        // Insert new node after rear
        rear->next = newNode;
        rear = newNode;

        // Maintain circular nature: last should point to front
        rear->next = front;
    }

    printf("%d inserted into circular queue.\n", item);
}

/*
    FUNCTION: dequeue
    PURPOSE : Remove (delete) element from the front of the circular queue
*/
void dequeue()
{
    if (front == NULL)
    {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }

    struct Node *temp = front;

    // Case 1: Only one element present
    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        // Move front to next node
        front = front->next;
        rear->next = front; // Maintain circular link
    }

    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

/*
    FUNCTION: display
    PURPOSE : Display all elements in circular queue
*/
void display()
{
    if (front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }

    struct Node *temp = front;

    printf("Circular Queue elements: ");

    // Loop runs until it reaches front again
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);

    printf("\n");
}

/*
    MAIN PROGRAM
    Menu-driven interface to perform queue operations
*/
int main()
{
    int choice, data;

    while (1)
    {
        printf("\n--- Queue Using Linked List Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            enqueue(data);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
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
