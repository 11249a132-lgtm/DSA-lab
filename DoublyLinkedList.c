/* Aim:
To develop a C program that implements a Doubly Linked List using dynamic memory allocation and performs operations
such as inserting nodes at the beginning, at the end, at a specific position, deleting a node by value, and displaying
all the nodes with both forward (next) and backward (prev) links.*/

#include <stdio.h>
#include <stdlib.h>

/*
    STRUCTURE OF DOUBLY LINKED LIST NODE
    Each node has:
    - data  : value
    - next  : pointer to next node
    - prev  : pointer to previous node
*/
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

/*
    FUNCTION: CreateNode
    PURPOSE : Dynamically creates a new node and returns its address
*/
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
    newNode->prev = NULL;

    return newNode;
}

/*
    FUNCTION: InsertAtBeginning
    PURPOSE : Inserts a node at the START of the Doubly Linked List
*/
void InsertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = CreateNode(data);

    newNode->next = *head; // New node points to old head
    newNode->prev = NULL;  // First node has no previous

    // If list was not empty, update old head's prev pointer
    if (*head != NULL)
        (*head)->prev = newNode;

    *head = newNode; // New node becomes head

    printf("Node %d inserted at beginning.\n", data);
}

/*
    FUNCTION: InsertAtEnd
    PURPOSE : Inserts node at the END of the list
*/
void InsertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = CreateNode(data);

    if (*head == NULL) // If list is empty
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;

        // Traverse to last node
        while (temp->next != NULL)
            temp = temp->next;

        // Link newNode at end
        temp->next = newNode;
        newNode->prev = temp;
    }

    printf("Node %d inserted at end.\n", data);
}

/*
    FUNCTION: InsertAtPosition
    PURPOSE : Insert node at specific position (1-based index)
*/
void InsertAtPosition(struct Node **head, int data, int position)
{
    if (position < 1)
    {
        printf("Invalid position!\n");
        return;
    }

    if (position == 1)
    {
        InsertAtBeginning(head, data);
        return;
    }

    struct Node *temp = *head;

    // Move pointer to node before desired position
    for (int k = 1; k < position - 1 && temp != NULL; k++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of range.\n");
        return;
    }

    struct Node *newNode = CreateNode(data);

    newNode->next = temp->next;
    newNode->prev = temp;

    // Fix backward link if not inserting at very end
    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;

    printf("Node %d inserted at position %d.\n", data, position);
}

/*
    FUNCTION: DeleteNode
    PURPOSE : Deletes first occurrence of given value from the list
*/
void DeleteNode(struct Node **head, int valueToDelete)
{
    if (*head == NULL)
    {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node *temp = *head;

    // If the value is in head node
    if (temp->data == valueToDelete)
    {
        *head = temp->next;

        if (*head != NULL)
            (*head)->prev = NULL;

        free(temp);
        printf("Node %d deleted.\n", valueToDelete);
        return;
    }

    // Search value in the list
    struct Node *before = *head;

    while (before->next != NULL)
    {
        if (before->next->data == valueToDelete)
        {
            temp = before->next;

            before->next = temp->next;

            if (temp->next != NULL)
                temp->next->prev = before;

            free(temp);

            printf("Node %d deleted.\n", valueToDelete);
            return;
        }
        before = before->next;
    }

    printf("Value %d not found.\n", valueToDelete);
}

/*
    FUNCTION: DisplayList
    PURPOSE : Displays entire Doubly Linked List with prev & next pointers
*/
void DisplayList(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;

    printf("\nDoubly Linked List: ");
    while (temp != NULL)
    {
        printf(" |Prev=%p|%d|Next=%p| -> ", temp->prev, temp->data, temp->next);
        temp = temp->next;
    }
}

/*
    MAIN PROGRAM
    Provides menu-driven operations
*/
int main()
{
    struct Node *head = NULL;
    int choice, data, pos;

    while (1)
    {
        printf("\n--- Doubly Linked List Menu ---\n");
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
