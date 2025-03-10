#ifndef HEAP_H
#define HEAP_H

#include "data_structures.h"

// Function declarations.
pHEAP createHeap(int capacity);                              // Creates a new heap with the specified capacity.
void freeHeap(pHEAP heap);                                   // Frees the memory allocated for the heap.
void Heapify(HEAP *pHeap, VERTEX **V, int i);                 // Maintains the heap property.
void BuildHeap(HEAP *pHeap, VERTEX **V);                      // Builds a min-heap.
void Insert(HEAP *pHeap, VERTEX **V, int index);              // Inserts a new element into the heap.
pVERTEX ExtractMin(HEAP *pHeap, VERTEX **V);                  // Extracts the vertex with the smallest key.
void DecreaseKey(HEAP *pHeap, VERTEX **V, int index, double newKey); // Decreases the key of a vertex.
void PrintHeap(HEAP *pHeap, VERTEX **V);                      // Prints the heap elements.
void PrintArray(VERTEX **V, int n);                           // Prints the array of vertices.

#endif // HEAP_H
