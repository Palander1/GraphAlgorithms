#ifndef GRAPH_H
#define GRAPH_H

#include "data_structures.h"

// Structure representing a graph.
typedef struct TAG_GRAPH {
    int numVertices;      // Number of vertices.
    int numEdges;         // Number of edges.
    pVERTEX* vertices;    // Array of pointers to vertices.
    pNODE* adjacencyList; // Array of adjacency lists.
} GRAPH;

typedef GRAPH* pGRAPH;

// Function declarations.
pGRAPH createGraph(int numVertices, int numEdges);          // Creates a graph with specified vertices and edges.
void addEdge(pGRAPH graph, int edgeIndex, int u, int v, double weight, bool directed, bool rear); // Adds an edge to the graph.
void printAdjacencyList(pGRAPH graph);                      // Prints the adjacency list.
void freeGraph(pGRAPH graph);                               // Frees graph memory.
void dijkstra(pGRAPH graph, pHEAP heap, int source);         // Computes shortest paths using Dijkstra's algorithm.
void printPath(pGRAPH graph, int destination);              // Prints the shortest path to the destination.

#endif // GRAPH_H
