//Andrew Palmer 1228231669

#include "stack.h"
#include <iostream>

using namespace std;

// Creates a stack with the specified capacity.
pSTACK createStack(int capacity) {
    pSTACK stack = new STACK;
    stack->capacity = capacity;
    stack->top = -1; // Empty stack.
    stack->elements = new pVERTEX[capacity]; // Allocate array for vertices.
    return stack;
}

// Pushes a vertex onto the stack.
void pushStack(pSTACK stack, pVERTEX vertex) {
    if (stack->top == stack->capacity - 1) {
        cerr << "Error: Stack overflow\n";
        return;
    }
    stack->elements[++stack->top] = vertex; // Add vertex and increment top.
}

// Pops a vertex from the stack.
pVERTEX popStack(pSTACK stack) {
    if (stack->top == -1) {
        cerr << "Error: Stack underflow\n";
        return nullptr;
    }
    return stack->elements[stack->top--]; // Return the top element and decrement top.
}

// Checks if the stack is empty.
bool isEmptyStack(pSTACK stack) {
    return stack->top == -1;
}

// Frees the stack's memory.
void freeStack(pSTACK stack) {
    if (!stack)
        return;
    delete[] stack->elements; // Free the array of elements.
    delete stack; // Free the stack structure.
}
