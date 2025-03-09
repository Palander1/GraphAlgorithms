//Andrew Palmer 1228231669

#ifndef _UTIL_H
#define _UTIL_H 1

#include "data_structures.h"
#include "graph.h"
#include "stack.h"

int nextInstruction(char *Word, double *Key); //parses next instruction
bool validateGraphType(const char *graphType); //validates input graph type
bool validateFlag(int flag); //validates input 0 or 1
void printUsageError(); //prints error message for invalid usage
bool readLineAndTokenize(const char *line, int &edgeIndex, int &u, int &v, double &weight); //reads and tokenizes a line from input file
bool parseArguments(int argc, char** argv, char*& inputFile, char*& graphType, int& flag); //validates and parses arguments
pGRAPH readGraphFromFile(const char* filename, const char* graphType, int flag); //reads input file and constructs graph
void printInvalidInstructionError(); //prints error for unrecognized instructions
void cleanup(pGRAPH graph, pHEAP heap, pSTACK stack); //frees memory for graph, heap, and stack

#endif
