#ifndef MAIN_H
#define MAIN_H

#include "heap.h"
#include "stack.h"
#include "graph.h"
#include "util.h"

// Function declarations.

// Initializes the system with the input file, graph type, and flag.
bool initializeSystem(const char* inputFile, const char* graphType, int flag, pGRAPH &graph, pHEAP &heap, pSTACK &stack);

// Processes a single instruction and performs the corresponding action.
void processInstruction(pGRAPH graph, pHEAP heap, pSTACK stack, const char* instruction, double key);

// Prints the adjacency list of the graph.
void handlePrintADJ(pGRAPH graph);

// Computes and prints the shortest path from source to destination.
void handleSinglePair(pGRAPH graph, pHEAP heap, int source, int destination);

// Computes and prints the shortest paths from a single source to all reachable nodes.
void handleSingleSource(pGRAPH graph, pHEAP heap, int source);

// Prints the length of a shortest path.
void handlePrintLength(pGRAPH graph, int source, int destination);

// Prints the shortest path.
void handlePrintPath(pGRAPH graph, pSTACK stack, int source, int destination);

#endif // MAIN_H
