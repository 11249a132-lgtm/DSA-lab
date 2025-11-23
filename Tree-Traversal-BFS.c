/* Aim:
To write a C program that constructs a Binary Search Tree (BST) dynamically and performs#include <stdio.h>
#include <stdlib.h>

// Queue for Level Order Traversal (BFS)
struct Node **queue;   // Will store addresses of tree nodes
int front = -1, rear = -1, MAX;

/*
    TREE NODE STRUCTURE
    Each node of BST contains:
    - data  : integer value
    - left  : pointer to left child
    - right : pointer to right child
*/
struct Node
{
    int data;
    struct Node *left, *right;
};

/*
    FUNCTION: createNode
    PURPOSE : Allocates memory and creates a new tree node
*/
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

/*
    FUNCTION: insert
    PURPOSE : Insert a value into the BST (recursive)
*/
struct Node *insert(struct Node *root, int value)
{
    // If tree is empty, new node becomes root
    if (root == NULL)
    {
        return createNode(value);
    }

    // Insert in left subtree
    if (value < root->data)
        root->left = insert(root->left, value);

    // Insert in right subtree
    else
        root->right = insert(root->right, value);

    return root;
}

/*
    QUEUE FUNCTIONS FOR BFS (LEVEL ORDER TRAVERSAL)
*/

// Insert (enqueue) a tree node pointer into queue
void enqueue(struct Node *temp)
{
    if (rear == MAX - 1)
        return; // Queue full → cannot enqueue

    if (front == -1)
        front = 0; // First insertion

    queue[++rear] = temp;
}

// Remove (dequeue) a tree node pointer from queue
struct Node *dequeue()
{
    if (front == -1 || front > rear)
        return NULL; // Queue empty

    return queue[front++];
}

/*
    FUNCTION: levelOrder
    PURPOSE : Perform Level Order Traversal (BFS) of BST
*/
void levelOrder(struct Node *root)
{
    if (root == NULL)
        return;

    enqueue(root); // Start BFS with root

    while (front <= rear)
    {
        struct Node *current = dequeue(); // Get next node
        printf("%d ", current->data);

        // Enqueue left child if exists
        if (current->left != NULL)
            enqueue(current->left);

        // Enqueue right child if exists
        if (current->right != NULL)
            enqueue(current->right);
    }
}

/*
    MAIN FUNCTION
    Builds BST dynamically from user values and prints BFS traversal
*/
int main()
{
    int value;
    struct Node *root = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &MAX);

    // Allocate queue dynamically
    queue = (struct Node **)malloc(MAX * sizeof(struct Node *));

    printf("Enter %d values:\n", MAX);

    // Insert values dynamically into BST
    for (int i = 0; i < MAX; i++)
    {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nLevel Order Traversal: ");
    levelOrder(root);

    return 0;
}
 Level Order Traversal (Breadth-First Search) using a queue implemented with dynamic memory allocation.*/
