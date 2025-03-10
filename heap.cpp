#include "heap.h"
#include <iostream>
#include <cmath>
#include <cstdlib>

// Creates a new heap with the specified capacity.
pHEAP createHeap(int capacity) {
    pHEAP heap = (pHEAP)malloc(sizeof(HEAP));
    heap->capacity = capacity;
    heap->size = 0;
    heap->H = (int*)malloc((capacity + 1) * sizeof(int)); // Allocate space for indices.
    return heap;
}

// Maintains the heap property.
void Heapify(HEAP *pHeap, VERTEX **V, int i) {
    int left = 2 * i;
    int right = 2 * i + 1;
    int smallest = i;

    if (left <= pHeap->size && V[pHeap->H[left]]->key < V[pHeap->H[smallest]]->key)
        smallest = left;

    if (right <= pHeap->size && V[pHeap->H[right]]->key < V[pHeap->H[smallest]]->key)
        smallest = right;

    if (smallest != i) {
        // Swap indices in H.
        int temp = pHeap->H[i];
        pHeap->H[i] = pHeap->H[smallest];
        pHeap->H[smallest] = temp;

        // Update positions in V.
        V[pHeap->H[i]]->position = i;
        V[pHeap->H[smallest]]->position = smallest;

        Heapify(pHeap, V, smallest);
    }
}

// Builds a min-heap.
void BuildHeap(HEAP *pHeap, VERTEX **V) {
    pHeap->size = pHeap->capacity;

    for (int i = 1; i <= pHeap->size; i++) {
        pHeap->H[i] = i;            // Initialize heap with vertex indices.
        V[i]->position = i;         // Set position in V.
    }

    for (int i = pHeap->size / 2; i >= 1; i--) {
        Heapify(pHeap, V, i);
    }
}

// Inserts a new element into the heap.
void Insert(HEAP *pHeap, VERTEX **V, int index) {
    if (V[index]->position != 0) {
        std::cerr << "Error: V[" << index << "] already in the heap\n";
        return;
    }

    pHeap->size++;
    pHeap->H[pHeap->size] = index;  // Add index to H.
    V[index]->position = pHeap->size;

    int i = pHeap->size;
    while (i > 1 && V[pHeap->H[i]]->key < V[pHeap->H[i / 2]]->key) {
        // Swap with parent.
        int temp = pHeap->H[i];
        pHeap->H[i] = pHeap->H[i / 2];
        pHeap->H[i / 2] = temp;

        // Update positions in V.
        V[pHeap->H[i]]->position = i;
        V[pHeap->H[i / 2]]->position = i / 2;

        i = i / 2;
    }
}

// Decreases the key of a specific element and maintains the heap property.
void DecreaseKey(HEAP *pHeap, VERTEX **V, int index, double newKey) {
    if (V[index]->position == 0) {
        return;
    }

    if (newKey >= V[index]->key) {
        return;
    }

    V[index]->key = newKey;
    int i = V[index]->position;

    while (i > 1 && V[pHeap->H[i]]->key < V[pHeap->H[i / 2]]->key) {
        // Swap with parent.
        int temp = pHeap->H[i];
        pHeap->H[i] = pHeap->H[i / 2];
        pHeap->H[i / 2] = temp;

        // Update positions in V.
        V[pHeap->H[i]]->position = i;
        V[pHeap->H[i / 2]]->position = i / 2;

        i = i / 2;
    }
}

// Extracts the minimum element (root) from the heap.
VERTEX* ExtractMin(HEAP *pHeap, VERTEX **V) {
    if (pHeap->size == 0) {
        std::cerr << "Error: heap is empty\n";
        return nullptr;
    }

    int minIndex = pHeap->H[1];  // Root contains the smallest element.

    // Move last element to root and decrease size.
    pHeap->H[1] = pHeap->H[pHeap->size];
    V[pHeap->H[1]]->position = 1;
    V[minIndex]->position = 0;  // Removed from heap.
    pHeap->size--;

    Heapify(pHeap, V, 1);

    return V[minIndex];
}

// Prints the current state of the heap.
void PrintHeap(HEAP *pHeap, VERTEX **V) {
    if (pHeap == nullptr || pHeap->capacity == 0) {
        std::cerr << "Error: heap is NULL\n";
        return;
    }

    std::cout << "Capacity = " << pHeap->capacity << ", size = " << pHeap->size << "\n";
    for (int i = 1; i <= pHeap->size; i++) {
        std::cout << "H[" << i << "] = " << V[pHeap->H[i]]->index << "\n";
    }
}

// Prints the array of elements (V).
void PrintArray(VERTEX **V, int n) {
    for (int i = 1; i <= n; i++) {
        std::cout << i << " " << V[i]->key << " " << V[i]->position << "\n";
    }
}

// Frees the memory allocated for the heap.
void freeHeap(pHEAP heap) {
    if (heap) {
        free(heap->H); // Free the array of indices.
        free(heap);    // Free the heap structure.
    }
}
