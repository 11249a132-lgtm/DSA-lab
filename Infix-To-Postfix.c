/* Aim:
To write a C program to convert an arithmetic expression from infix notation to postfix notation using a stack, by applying operator precedence and parenthesis handling.
******************************************
Short form of Infox To Postfix Conversion
******************************************
1. Ask user for size of the Infix epresssion - MAX
2. Create THREE string variables of size 'MAX' - STACK, Infix, Postfix
3. Save the Infix Expresssion entered by the user in a variable - Infix
4. Read one char (Token) at a time until the end of string reached - c
    A. If c == Operand Then Add to Output (Postfix)
    B. If c == '(' Then Push(c) to Stack
    c. If c == ')' Then Pop until you find '(' and ingore both
    D. If c == Operator Then Compare current Token (c) with Stack Top using Peek
        Case 1: Stack is Empty >> Push(c)
        Case 2: Stack Top Token Precedence >= Current Token (c) precendence Then Pop untill conditin failed
        Case 3: Stack Top Token Precedence < Current Token (c) precendence Then Push(c)
5. Pop() All remaining tokens from Stack
*/

#include <stdio.h>
#include <stdlib.h>

int TOP = -1, MAX;
char *STACK;

void Display()
{
    printf("Current Stack elements are -");
    for (int i = 0; i <= TOP; i++)
    {
        printf("[%c,]", STACK[i]);
    }
    printf("\n");
}

void Push(char item)
{
    if (TOP == MAX - 1)
    {
        printf("Stack is overflow");
    }
    else
    {
        TOP = TOP + 1;
        STACK[TOP] = item;
    }
}

char Pop()
{
    if (TOP == -1)
    {
        printf("Stack is underflow / empty\n");
        return '\0';
    }
    else
    {
        char item = STACK[TOP];
        TOP = TOP - 1;
        return item;
    }
}

char Peek()
{
    if (TOP == -1)
    {
        // printf("Stack is underflow / empty\n");
        return '\0';
    }
    else
    {
        return STACK[TOP];
    }
}

int GetPrecedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1; // lowest precedence
    case '*':
    case '/':
        return 2;
    case '^':
        return 3; // highest precedence
    default:
        return 0; // consider it as operand
    }
}

int main()
{
    printf("Enter the size of infix expression: ");
    scanf("%d", &MAX);

    STACK = (char *)malloc(MAX * sizeof(char));
    char infix[MAX];
    char postfix[MAX];

    printf("Please enter the infix string of size %d: ", MAX);
    scanf("%s", infix);

    int TokenPrecedence, j = 0, i = 0;
    char c, temp;

    // Reading one token at a time
    while ((c = infix[i]) != '\0')
    // for (int i = 0; i < MAX; i++)
    {
        // c = infix[i];
        TokenPrecedence = GetPrecedence(c); // Current token at a time
        if (TokenPrecedence > 0)            // Current token is Operator
        {
            while (TokenPrecedence <= GetPrecedence(Peek())) // Current Token <= Stack Top Token
            {
                postfix[j++] = Pop();
            }
            Push(c);
        }
        else // Current token is operand or '(' or ')'
        {
            switch (c)
            {
            case '(':
                Push(c);
                break;
            case ')':
                while (Peek() != '(')
                {
                    postfix[j++] = Pop();
                }
                Pop();
                break;
            default:
                postfix[j++] = c;
                break;
            }
        }
        i++;
    }

    // Pop All remaining tokens from stack
    while (Peek() != '\0')
    {
        char c = Pop();
        postfix[j++] = c;
    }
    postfix[j] = '\0';
    printf("Postfix notation is : %s", postfix);
    return 0;
}
