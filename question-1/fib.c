#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

// Define the fibonacci function using dynamic programming
int fibonacci(int num)
{
    int n = abs(num);
    // printf("%d",n);
    int *fib = (int *)malloc((n + 1) * sizeof(int)); // Allocate memory for the array
    fib[0] = 0;                                      // Base case 1: fib(0) = 0
    fib[1] = 1;                                      // Base case 2: fib(1) = 1
    for (int i = 2; i <= n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2]; // Use the recurrence relation to compute the remaining values
    }
    // printf("%d",fib[n-1]);
    return fib[n - 1];
}

// Define the makeFunc function to create new nodes
Node *makeFunc(TypeTag type)
{
    Node *node = (Node *)malloc(sizeof(Node)); // Allocate memory for the new node
    node->type = type;                         // Set the type of the node
    node->value = 0;                           // Initialize the value of the node to 0
    node->left = NULL;                         // Set the left child to NULL
    node->right = NULL;                        // Set the right child to NULL
    return node;
}

// Define the makeInt function to create new integer nodes
Node *makeInt(int value)
{
    Node *node = (Node *)malloc(sizeof(Node)); // Allocate memory for the new node
    node->type = INT;                          // Set the type of the node to INT
    node->value = value;                       // Set the value of the node
    node->left = NULL;                         // Set the left child to NULL
    node->right = NULL;                        // Set the right child to NULL
    return node;
}

// Define the calc function to evaluate nodes
void calc(Node *node)
{
    switch (node->type)
    {
    case INT:
        // If the node is an INT, print its value and return
        // printf("%d\n", node->value);
        break;
    case ADD:
        // If the node is an ADD, recursively evaluate its left and right children
        calc(node->left);
        calc(node->right);
        // Add the values of the left and right children and store the result in the current node
        node->value = node->left->value + node->right->value;
        // Print the value of the current node
        printf("add : %d\n", node->value);
        break;
    case SUB:
        // If the node is a SUB, recursively evaluate its left and right children
        calc(node->left);
        calc(node->right);
        // Subtract the value of the right child from the value of the left child and store the result in the current node
        node->value = node->left->value - node->right->value;
        // Print the value of the current node
        printf("sub : %d\n", node->value);
        break;
    case MUL:
        // If the node is a MUL, recursively evaluate its left and right children
        calc(node->left);
        calc(node->right);
        // Multiply the values of the left and right children and store the result in the current node
        node->value = node->left->value * node->right->value;
        // Print the value of the current node
        printf("mul : %d\n", node->value);
        break;
    case FIBO:
        // If the node is a FIBO, recursively evaluate its left child
        // printf("%s","call here");
        calc(node->left);
        // Calculate the fibonacci sequence and store the result in the current node
        node->value = fibonacci(node->left->value);
        // Print the value of the current node
        printf("fibo: %d\n", node->value);
        break;
    default:
        // If the node has an unknown type, print an error message and return
        printf("Error: Unknown node type\n");
        return;
    }
}

// Define the main function
int main()
{
    // Create the nodes for the arithmetic operations and the fibonacci sequence
    // Node *add = (*makeFunc(ADD))(10, 6);
    // Node *mul = (*makeFunc(MUL))(5, 4);
    // Node *sub = (*makeFunc(SUB))(mul, add);
    // Node *fibo = (*makeFunc(SUB))(sub, NULL);
    Node *add = makeFunc(ADD);
    add->left = makeInt(10);
    add->right = makeInt(6);

    Node *mul = makeFunc(MUL);
    mul->left = makeInt(5);
    mul->right = makeInt(4);

    Node *sub = makeFunc(SUB);
    // printf("%s","call here");
    sub->left = add;
    sub->right = mul;

    Node *fibo = makeFunc(FIBO);
    fibo->left = sub;
    fibo->right = NULL;

    // Evaluate the nodes and print the results
    // calc(add);
    // calc(mul);
    // calc(sub);
    calc(fibo);

    free(fibo);

    return 0;
}