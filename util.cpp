//Andrew Palmer 1228231669

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <cstdio>
#include "util.h"
#include "heap.h"

using namespace std;

// Parses the next instruction from stdin.
int nextInstruction(char *Word, double *Key) {
    int returnV;
    fscanf(stdin, "%s", Word);

    if (strcmp(Word, "Stop") == 0)
        return 1;
    if (strcmp(Word, "PrintADJ") == 0)
        return 1;
    if (strcmp(Word, "SinglePair") == 0) {
        returnV = fscanf(stdin, "%lf", Key); // Key stores source vertex.
        if (returnV == 1)
            return 1;
        else
            return 0;
    }
    if (strcmp(Word, "SingleSource") == 0) {
        returnV = fscanf(stdin, "%lf", Key); // Key stores source vertex.
        if (returnV == 1)
            return 1;
        else
            return 0;
    }
    if (strcmp(Word, "PrintLength") == 0) {
        returnV = fscanf(stdin, "%lf", Key); // Key stores source vertex.
        if (returnV == 1)
            return 1;
        else
            return 0;
    }
    if (strcmp(Word, "PrintPath") == 0) {
        returnV = fscanf(stdin, "%lf", Key); // Key stores source vertex.
        if (returnV == 1)
            return 1;
        else
            return 0;
    }

    return 0;
}

// Parses command-line arguments and validates them.
bool parseArguments(int argc, char** argv, char*& inputFile, char*& graphType, int& flag) {
    if (argc != 4) {
        printUsageError();
        return false;
    }

    inputFile = argv[1];
    graphType = argv[2];

    if (!validateGraphType(graphType)) {
        cerr << "Error: Invalid graph type. Must be 'DirectedGraph' or 'UndirectedGraph'.\n";
        return false;
    }

    flag = atoi(argv[3]);
    if (!validateFlag(flag)) {
        cerr << "Error: Invalid flag. Must be 0 or 1.\n";
        return false;
    }

    return true;
}

// Validates the graph type.
bool validateGraphType(const char *graphType) {
    return strcmp(graphType, "DirectedGraph") == 0 || strcmp(graphType, "UndirectedGraph") == 0;
}

// Validates the flag (0 or 1).
bool validateFlag(int flag) {
    return flag == 0 || flag == 1;
}

// Prints an error message for incorrect usage.
void printUsageError() {
    cerr << "Usage: ./PJ3 <InputFile> <GraphType> <Flag>\n";
}

// Reads a line from the graph input file and tokenizes it.
bool readLineAndTokenize(const char *line, int &edgeIndex, int &u, int &v, double &weight) {
    return sscanf(line, "%d %d %d %lf", &edgeIndex, &u, &v, &weight) == 4;
}

// Reads the graph data from a file and populates the graph structure.
pGRAPH readGraphFromFile(const char *filename, const char *graphType, int flag) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error: Cannot open input file " << filename << endl;
        return nullptr;
    }

    int numVertices, numEdges;
    inputFile >> numVertices >> numEdges;

    pGRAPH graph = createGraph(numVertices, numEdges);

    string line;
    getline(inputFile, line); // Consume the remaining newline.
    int edgeIndex = 1;        // Edge index starts at 1.

    while (getline(inputFile, line)) {
        int u, v;
        double weight;

        if (readLineAndTokenize(line.c_str(), edgeIndex, u, v, weight)) {
            bool directed = strcmp(graphType, "DirectedGraph") == 0;
            bool rear = (flag == 1);
            addEdge(graph, edgeIndex++, u, v, weight, directed, rear);
        } else {
            cerr << "Error: Invalid line format in input file: " << line << endl;
        }
    }

    inputFile.close();
    return graph;
}

// Prints an error for invalid instructions.
void printInvalidInstructionError() {
    cerr << "Error: Invalid instruction.\n";
}

// Cleans up allocated memory.
void cleanup(pGRAPH graph, pHEAP heap, pSTACK stack) {
    if (graph)
        freeGraph(graph);
    if (heap)
        freeHeap(heap);
    if (stack)
        freeStack(stack);
}
