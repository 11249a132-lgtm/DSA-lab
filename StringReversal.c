/* Aim:
To write a C program that uses a stack (implemented using an array) to reverse a given string by pushing each character onto the stack and then popping them in reverse order.*/

#include <stdio.h>
#include <stdlib.h>

int top = -1;     // Top of stack
int size;         // Size of the stack (same as string length)
char *STACK;      // Dynamic array to act as stack

/*
    FUNCTION: push
    PURPOSE : Push a character onto the stack
*/
void push(char item)
{
    if (top == (size - 1))   // Overflow condition
    {
        printf("Stack is already full, no additional push allowed - Overflow\n");
    }
    else
    {
        top = top + 1;       // Increment top
        STACK[top] = item;   // Insert character
    }
}

/*
    FUNCTION: pop
    PURPOSE : Pop (remove and return) top-most character from stack
*/
char pop()
{
    char temp = STACK[top];  // Store top element
    top = top - 1;           // Decrement top
    return temp;             // Return popped character
}

int main()
{
    printf("Enter the size of string to reverse: ");
    scanf("%d", &size);

    char input[size];   // Array to store input string

    // Allocate memory for STACK dynamically
    STACK = (char *)malloc(size * sizeof(char));

    printf("Enter the string of size %d to reverse: ", size);
    scanf("%s", input);     // Read string

    // PUSH each character of string into Stack
    for (int i = 0; i <= size - 1; i++)
    {
        push(input[i]);
    }

    // POP each character to print reversed string
    printf("Reversed string is:\n");
    for (int i = 0; i <= size - 1; i++)
    {
        printf("%c", pop());
    }

    return 0;
}
