#ifndef NODE_H
#define NODE_H

typedef enum TypeTag {
    INT,
    ADD,
    SUB,
    MUL,
    FIBO
} TypeTag;

// Define the Node struct
typedef struct Node {
    TypeTag type;   // The type of the node
    int value;      // The value of the node (if it's an INT)
    struct Node* left;  // The left child of the node (if it has one)
    struct Node* right; // The right child of the node (if it has one)
} Node;

#endif