//Andrew Palmer 1228231669

#include <iostream>
#include <iomanip>
#include <cstdio>
#include "graph.h"
#include "heap.h"

using namespace std;

// Creates a graph with the specified number of vertices and edges.
pGRAPH createGraph(int numVertices, int numEdges) {
    pGRAPH graph = new GRAPH;

    graph->numVertices = numVertices;
    graph->numEdges = numEdges;

    // Allocate memory for vertices and adjacency lists.
    graph->vertices = new pVERTEX[numVertices + 1];
    graph->adjacencyList = new pNODE[numVertices + 1];

    // Initialize vertices and adjacency lists.
    for (int i = 1; i <= numVertices; i++) {
        graph->vertices[i] = new VERTEX;
        graph->vertices[i]->index = i;
        graph->vertices[i]->key = DBL_MAX; // Infinite key.
        graph->vertices[i]->color = WHITE; // Unvisited.
        graph->vertices[i]->pi = 0;        // No predecessor.
        graph->vertices[i]->position = 0;  // Not in the heap.
        graph->adjacencyList[i] = nullptr;
    }

    return graph;
}

// Adds an edge to the graph.
void addEdge(pGRAPH graph, int edgeIndex, int u, int v, double weight, bool directed, bool rear) {
    // Create a new adjacency list node.
    pNODE newNode = new NODE;
    newNode->index = u;
    newNode->u = u;
    newNode->v = v;
    newNode->w = weight;
    newNode->next = nullptr;

    // Add the edge at the front or rear of the adjacency list.
    if (rear) {
        pNODE current = graph->adjacencyList[u];
        if (!current) {
            graph->adjacencyList[u] = newNode;
        } else {
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    } else {
        newNode->next = graph->adjacencyList[u];
        graph->adjacencyList[u] = newNode;
    }

    // If the graph is undirected, add the reverse edge.
    if (!directed) {
        pNODE reverseNode = new NODE;
        reverseNode->index = v;
        reverseNode->u = v;
        reverseNode->v = u;
        reverseNode->w = weight;
        reverseNode->next = nullptr;

        if (rear) {
            pNODE current = graph->adjacencyList[v];
            if (!current) {
                graph->adjacencyList[v] = reverseNode;
            } else {
                while (current->next) {
                    current = current->next;
                }
                current->next = reverseNode;
            }
        } else {
            reverseNode->next = graph->adjacencyList[v];
            graph->adjacencyList[v] = reverseNode;
        }
    }
}

// Prints the adjacency list representation of the graph.
void printAdjacencyList(pGRAPH graph) {
    for (int i = 1; i <= graph->numVertices; i++) {
        // Print the vertex index.
        printf("ADJ[%d]:", i);
        pNODE current = graph->adjacencyList[i];
        while (current) {
            // Print each adjacency node.
            printf("-->[%d %d: %4.2lf]", current->index, current->v, current->w);
            current = current->next;
        }
        printf("\n");
    }
}

// Dijkstra's algorithm for shortest paths.
void dijkstra(pGRAPH graph, pHEAP heap, int source) {
    // Initialize all vertices.
    for (int i = 1; i <= graph->numVertices; i++) {
        graph->vertices[i]->key = DBL_MAX; // Set to infinity.
        graph->vertices[i]->pi = 0;        // No predecessor.
        graph->vertices[i]->position = 0;  // Mark as not in the heap.
    }

    graph->vertices[source]->key = 0; // Distance to source is 0.

    // Insert all vertices into the heap.
    for (int i = 1; i <= graph->numVertices; i++) {
        Insert(heap, graph->vertices, i);
    }

    // Process vertices.
    while (heap->size > 0) {
        pVERTEX u = ExtractMin(heap, graph->vertices); // Get vertex with smallest distance.
        u->position = 0;
        pNODE current = graph->adjacencyList[u->index];

        while (current) {
            int v = current->v;
            double weight = current->w;

            // Relax the edge.
            if (graph->vertices[u->index]->key + weight < graph->vertices[v]->key) {
                double newKey = graph->vertices[u->index]->key + weight;
                graph->vertices[v]->key = newKey;
                graph->vertices[v]->pi = u->index; // Update predecessor.

                // Only decrease key if the vertex is still in the heap.
                if (graph->vertices[v]->position != 0) {
                    DecreaseKey(heap, graph->vertices, v, newKey);
                } else {
                    Insert(heap, graph->vertices, v);
                }
            }
            current = current->next;
        }
    }
}

// Prints the shortest path to the destination.
void printPath(pGRAPH graph, int destination) {
    if (graph->vertices[destination]->pi == 0) { // If no predecessor.
        std::cout << destination;
    } else {
        printPath(graph, graph->vertices[destination]->pi); // Recursively print the path.
        std::cout << " -> " << destination;
    }
}

// Frees the memory allocated for the graph.
void freeGraph(pGRAPH graph) {
    if (!graph) return;

    // Free adjacency lists.
    for (int i = 1; i <= graph->numVertices; i++) {
        pNODE current = graph->adjacencyList[i];
        while (current) {
            pNODE temp = current;
            current = current->next;
            delete temp;
        }
    }

    // Free vertices.
    for (int i = 1; i <= graph->numVertices; i++) {
        delete graph->vertices[i];
    }

    // Free the graph structure.
    delete[] graph->vertices;
    delete[] graph->adjacencyList;
    delete graph;
}
