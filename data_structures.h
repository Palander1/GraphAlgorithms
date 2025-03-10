#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <cfloat>

// Enumeration for vertex colors.
enum COLOR {
    WHITE,
    GRAY,
    BLACK
};

// Structure representing a graph vertex.
typedef struct TAG_VERTEX {
    int   index;     // Vertex index.
    COLOR color;     // Vertex color.
    double key;      // Distance from source.
    int   pi;        // Predecessor in the shortest path.
    int   position;  // Position in the min-heap.
} VERTEX;

typedef VERTEX* pVERTEX;

// Structure representing a node in the adjacency list.
typedef struct TAG_NODE {
    int index;              // Edge index.
    int u, v;               // Start and end vertices.
    double w;               // Weight of the edge.
    struct TAG_NODE* next;  // Pointer to the next node.
} NODE;

typedef NODE* pNODE;

// Structure representing a min-heap.
typedef struct TAG_HEAP {
    int capacity;   // Maximum capacity of the heap.
    int size;       // Current size of the heap.
    int* H;         // Array of pointers to vertices.
} HEAP;

typedef HEAP* pHEAP;

#endif // DATA_STRUCTURES_H
