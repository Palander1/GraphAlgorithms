#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <cstdio>
#include "util.h"
#include "heap.h"
#include "stack.h"
#include "graph.h"
#include "main.h"

int main(int argc, char** argv) {
    // Validate and parse commandline arguments.
    char* inputFile = nullptr;
    char* graphType = nullptr;
    int flag = 0;

    if (!parseArguments(argc, argv, inputFile, graphType, flag)) {
        printUsageError();
        return 1;
    }

    // Initialize system components.
    pGRAPH graph = nullptr;
    pHEAP heap = nullptr;
    pSTACK stack = nullptr;

    if (!initializeSystem(inputFile, graphType, flag, graph, heap, stack)) {
        std::cerr << "Error: Failed to initialize the system.\n";
        cleanup(graph, heap, stack);
        return 1;
    }

    // Process instructions from stdin.
    char instruction[100];
    double key = 0.0;

    while (true) {
        if (!nextInstruction(instruction, &key)) {
            printInvalidInstructionError();
            continue;
        }

        if (strcmp(instruction, "Stop") == 0) {
            break;
        }

        processInstruction(graph, heap, stack, instruction, key);
    }

    // Cleanup resources.
    cleanup(graph, heap, stack);
    return 0;
}

// Initializes the system with graph, heap, and stack.
bool initializeSystem(const char* inputFile, const char* graphType, int flag, pGRAPH &graph, pHEAP &heap, pSTACK &stack) {
    graph = readGraphFromFile(inputFile, graphType, flag);
    if (!graph) {
        return false;
    }

    heap = createHeap(graph->numVertices);
    if (!heap) {
        freeGraph(graph);
        return false;
    }

    stack = createStack(graph->numVertices);
    if (!stack) {
        freeHeap(heap);
        freeGraph(graph);
        return false;
    }

    return true;
}

// Processes a single instruction and calls the appropriate handler.
void processInstruction(pGRAPH graph, pHEAP heap, pSTACK stack, const char* instruction, double key) {
    if (strcmp(instruction, "PrintADJ") == 0) {
        handlePrintADJ(graph);
    } else if (strcmp(instruction, "SinglePair") == 0) {
        int source = static_cast<int>(key);
        int destination;
        std::cin >> destination;
        if (source < 1 || source > graph->numVertices || destination < 1 || destination > graph->numVertices) {
            return;
        }
        handleSinglePair(graph, heap, source, destination);
    } else if (strcmp(instruction, "SingleSource") == 0) {
        int source = static_cast<int>(key);
        if (source < 1 || source > graph->numVertices) {
            return;
        }
        handleSingleSource(graph, heap, source);
    } else if (strcmp(instruction, "PrintLength") == 0) {
        int source = static_cast<int>(key);
        int destination;
        std::cin >> destination;
        if (source < 1 || source > graph->numVertices || destination < 1 || destination > graph->numVertices) {
            return;
        }
        handlePrintLength(graph, source, destination);
    } else if (strcmp(instruction, "PrintPath") == 0) {
        int source = static_cast<int>(key);
        int destination;
        std::cin >> destination;
        if (source < 1 || source > graph->numVertices || destination < 1 || destination > graph->numVertices) {
            return;
        }
        handlePrintPath(graph, stack, source, destination);
    } else {
        printInvalidInstructionError();
    }
}

// Prints the adjacency list of the graph.
void handlePrintADJ(pGRAPH graph) {
    printAdjacencyList(graph);
}

// Computes and prints the shortest path from source to destination.
void handleSinglePair(pGRAPH graph, pHEAP heap, int source, int destination) {
    dijkstra(graph, heap, source); // Compute shortest paths from source.
}

// Computes and prints the shortest paths from a single source to all reachable nodes.
void handleSingleSource(pGRAPH graph, pHEAP heap, int source) {
    dijkstra(graph, heap, source); // Compute shortest paths from source.
}

// Prints the length of the shortest path.
void handlePrintLength(pGRAPH graph, int source, int destination) {
    if (graph->vertices[destination]->key == DBL_MAX) {
        // No path exists.
        printf("There is no path from %d to %d.\n", source, destination);
    } else {
        // Path exists.
        printf("The length of the shortest path from %d to %d is: %8.2lf\n",
               source, destination, graph->vertices[destination]->key);
    }
}

// Prints the shortest path.
void handlePrintPath(pGRAPH graph, pSTACK stack, int source, int destination) {
    // Check if Dijkstra's algorithm has been called.
    if (graph->vertices[source]->key == DBL_MAX) {
        return;
    }

    if (graph->vertices[destination]->key == DBL_MAX) {
        // Destination is unreachable.
        printf("There is no path from %d to %d.\n", source, destination);
        return;
    }

    // Trace the path from destination back to source.
    int current = destination;
    while (current != 0) {
        pushStack(stack, graph->vertices[current]); // Push vertex onto stack.
        current = graph->vertices[current]->pi;       // Move to predecessor.
    }

    // Print the path.
    printf("The shortest path from %d to %d is:\n", source, destination);
    bool isFirst = true;
    while (!isEmptyStack(stack)) {
        pVERTEX vertex = popStack(stack);
        if (!isFirst) {
            printf("-->");
        }
        isFirst = false;
        printf("[%d:%8.2lf]", vertex->index, vertex->key);
    }
    printf(".\n");
}
