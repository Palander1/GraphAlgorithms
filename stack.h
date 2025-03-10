#ifndef STACK_H
#define STACK_H

#include "data_structures.h"

// Stack structure.
typedef struct TAG_STACK {
    int capacity;      // Maximum capacity.
    int top;           // Index of the top element.
    pVERTEX* elements; // Array of pointers to vertices.
} STACK;

typedef STACK* pSTACK;

// Function declarations.
pSTACK createStack(int capacity);      // Creates a stack with the specified capacity.
void pushStack(pSTACK stack, pVERTEX vertex);  // Pushes a vertex onto the stack.
pVERTEX popStack(pSTACK stack);          // Pops a vertex from the stack.
bool isEmptyStack(pSTACK stack);         // Checks if the stack is empty.
void freeStack(pSTACK stack);            // Frees the memory allocated for the stack.

#endif // STACK_H
