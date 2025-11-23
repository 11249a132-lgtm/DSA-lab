/* Aim:
To write a C program to implement a queue using an array and perform basic queue operations such as enqueue (insertion), dequeue (deletion), and display, while handling overflow and underflow conditions.*/

#include <stdio.h>
#include <stdlib.h>

int front = -1, rear = -1, size;
int *QUEUE; // Dynamic array for queue

/*
    FUNCTION: enqueue
    PURPOSE : Insert (add) an element at the rear end of the queue
*/
void enqueue(int item)
{
    // Check overflow (queue full)
    if (rear == size - 1)
    {
        printf("Queue Overflow! Cannot insert.\n");
        return;
    }

    // If inserting first element
    if (front == -1)
        front = 0;

    rear++;               // Move rear forward
    QUEUE[rear] = item;   // Store item in queue
    printf("%d inserted into queue.\n", item);
}

/*
    FUNCTION: dequeue
    PURPOSE : Remove (delete) element from the front of queue
*/
void dequeue()
{
    // Underflow condition
    if (front == -1)
    {
        printf("Queue Underflow! Nothing to delete.\n");
        return;
    }

    int temp = QUEUE[front];  // Store element to delete
    front++;                  // Move front forward
    printf("Deleted element: %d\n", temp);

    // If all elements deleted, reset queue
    if (front > rear)
        front = rear = -1;
}

/*
    FUNCTION: display
    PURPOSE : Display all queue elements from front to rear
*/
void display()
{
    if (front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", QUEUE[i]);
    }
    printf("\n");
}

/*
    MAIN FUNCTION:
    Menu-driven program to demonstrate queue operations
*/
int main()
{
    int choice, data;

    printf("Enter size of Queue: ");
    scanf("%d", &size);

    // Allocate memory for queue dynamically
    QUEUE = (int *)malloc(size * sizeof(int));
    if (QUEUE == NULL)
    {
        printf("Memory allocation failed!\n");
        return 0;
    }

    // Menu loop
    while (1)
    {
        printf("\n--- Queue Menu ---\n");
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
            free(QUEUE); // Free memory before exit
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
