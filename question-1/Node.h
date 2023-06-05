#ifndef NODE_H
#define NODE_H

typedef enum TypeTag {
ADD,
SUB,
MUL,
DIV,
NULLTAG
} TypeTag;

typedef struct Node {
TypeTag type;
} Node;

#endif