/* Aim:
To write a C program that constructs a Binary Search Tree (BST) dynamically and performs Preorder, Inorder, and Postorder traversals to display the elements in different tree traversal orders.*/

#include <stdio.h>
#include <stdlib.h>

/*
    STRUCTURE OF TREE NODE
    Each node contains:
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
    PURPOSE : Creates a new node with given value
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
    PURPOSE : Insert a node into Binary Search Tree (BST)
              Uses recursive strategy.
*/
struct Node *insert(struct Node *root, int value)
{
    // Base Case: Tree is empty → new node becomes root
    if (root == NULL)
    {
        return createNode(value);
    }

    // If value is less → go to left subtree
    if (value < root->data)
        root->left = insert(root->left, value);

    // If value is greater or equal → go to right subtree
    else
        root->right = insert(root->right, value);

    return root;
}

/*
    PREORDER TRAVERSAL
    Order: ROOT → LEFT → RIGHT
*/
void preorder(struct Node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);  // Visit root
    preorder(root->left);       // Traverse left subtree
    preorder(root->right);      // Traverse right subtree
}

/*
    INORDER TRAVERSAL
    Order: LEFT → ROOT → RIGHT
    (Gives sorted output for BST)
*/
void inorder(struct Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);        // Visit left subtree
    printf("%d ", root->data);  // Visit root
    inorder(root->right);       // Visit right subtree
}

/*
    POSTORDER TRAVERSAL
    Order: LEFT → RIGHT → ROOT
*/
void postorder(struct Node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);      // Traverse left subtree
    postorder(root->right);     // Traverse right subtree
    printf("%d ", root->data);  // Visit root
}

/*
    MAIN FUNCTION
    Builds the BST using user input and displays all 3 traversals
*/
int main()
{
    int n, value;
    struct Node *root = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);

    // Insert nodes one by one into BST
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Preorder Traversal: ");
    preorder(root);

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    return 0;
}
