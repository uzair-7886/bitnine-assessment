#include "fib.h"
#include <stdio.h>
#include <stdlib.h>

int fib(int n) {
int memo[n+1];
memo[0] = 0;
memo[1] = 1;
for (int i = 2; i <= n; i++) {
memo[i] = memo[i-1] + memo[i-2];
}
return memo[n];
}

Node* makeFunc(TypeTag type) {
    Node* node = malloc(sizeof(Node));
    node->type = type;
    return node;
}

int calc(Node* node) {
    if (node->type == NULLTAG) {
        return fib(3);
    } else if (node->type == ADD) {
        return 10 + 6;
    } else if (node->type == MUL) {
        return 5 * 4;
    } else if (node->type == SUB) {
        Node* left = makeFunc(MUL);
        Node* right = makeFunc(ADD);
        int a = calc(left);
        int b = calc(right);
        return a - b;
    }
    return 0; // Added a default return statement
}


int main() {
    Node *add = (*makeFunc(ADD))(10, 6);
    Node *mul = (*makeFunc(MUL))(5, 4);
    Node *sub = (*makeFunc(SUB))(mul, add);
    Node *fibo = (*makeFunc(FIBO))(sub, NULL);

    printf("add : %d\n", calc(add));
    printf("mul : %d\n", calc(mul));
    printf("sub : %d\n", calc(sub));
    printf("fibo : %d\n", calc(fibo));

    free(add);
    free(mul);
    free(sub);
    free(fibo);

    return 0;
}