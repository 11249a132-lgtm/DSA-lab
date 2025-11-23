/*Aim:
To develop a C program that implements a singly linked list using dynamic memory allocation and performs basic operations such as:
1.Inserting a node at the beginning
2.Inserting a node at the end
3.Inserting a node at a specific position
4.Deleting a node by its value
5.Displaying all nodes in the linked list */

#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
struct Node
{
    int data;              // Data part of node
    struct Node *next;     // Pointer to next node
};

// Function to create a new node
struct Node *CreateNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/* Insert a new node at the beginning of list */
void InsertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = CreateNode(data);

    newNode->next = *head;   // New node points to current head
    *head = newNode;         // Head updated to new node

    printf("Node with data %d inserted at beginning.\n", data);
}

/* Insert a node at the end */
void InsertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = CreateNode(data);

    // If list is empty
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;

        // Traverse to last node
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }
    printf("Node with data %d inserted at end.\n", data);
}

/* Insert a node at a specific position (1-based indexing) */
void InsertAtPosition(struct Node **head, int data, int position)
{
    if (position < 1)
    {
        printf("Invalid position!\n");
        return;
    }

    // For inserting at head
    if (position == 1)
    {
        InsertAtBeginning(head, data);
        return;
    }

    struct Node *prev = *head;

    // Move to node before the position
    for (int k = 1; k < position - 1 && prev != NULL; k++)
    {
        prev = prev->next;
    }

    if (prev == NULL)
    {
        printf("Position out of range!\n");
        return;
    }

    struct Node *newNode = CreateNode(data);
    newNode->next = prev->next;  // Link new node to next node
    prev->next = newNode;        // Previous node points to new node

    printf("Node with data %d inserted at position %d.\n", data, position);
}

/* Delete a node by value */
void DeleteNode(struct Node **head, int valueToDelete)
{
    if (*head == NULL)
    {
        printf("List is empty, delete operation cannot be performed.\n");
        return;
    }

    struct Node *temp = *head;

    // If value found at head
    if (temp->data == valueToDelete)
    {
        *head = temp->next;
        free(temp);
        printf("Data %d deleted from list.\n", valueToDelete);
        return;
    }

    struct Node *prev = *head;

    // Traverse list to locate the value
    while (prev->next != NULL)
    {
        if (prev->next->data == valueToDelete)
        {
            temp = prev->next;
            prev->next = temp->next;
            free(temp);
            printf("Data %d deleted.\n", valueToDelete);
            return;
        }
        prev = prev->next;
    }

    printf("Element %d not found.\n", valueToDelete);
}

/* Display all nodes */
void DisplayList(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("\nLinked List: ");

    while (temp != NULL)
    {
        printf("|Addr=%p|%d|Next=%p| -> ", temp, temp->data, temp->next);
        temp = temp->next;
    }
}

int main()
{
    struct Node *head = NULL;
    int choice, data, pos;

    while (1)
    {
        printf("\n\n--- Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete by Value\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            InsertAtBeginning(&head, data);
            break;

        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            InsertAtEnd(&head, data);
            break;

        case 3:
            printf("Enter data and position: ");
            scanf("%d %d", &data, &pos);
            InsertAtPosition(&head, data, pos);
            break;

        case 4:
            printf("Enter value to delete: ");
            scanf("%d", &data);
            DeleteNode(&head, data);
            break;

        case 5:
            DisplayList(head);
            break;

        case 6:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
