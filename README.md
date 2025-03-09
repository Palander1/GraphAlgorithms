# Graph Algorithms Project

A C++ project implementing Dijkstra's algorithm using custom data structures (graph, min-heap, and stack).

## File Structure

- **data_structures.h**: Data type definitions.
- **graph.h / graph.cpp**: Graph creation, edge insertion, and Dijkstra's algorithm.
- **heap.h / heap.cpp**: Min-heap implementation.
- **stack.h / stack.cpp**: Stack operations for path reconstruction.
- **util.h / util.cpp**: Command-line parsing and file I/O utilities.
- **main.h / main.cpp**: Main program and instruction processing.

## Compilation

To compile the project, run:
make

## Usage
-----
./PJ3 INPUT_FILE GRAPH_TYPE FLAG

    <InputFile> = Path to the graph data file
    <GraphType> = "DirectedGraph" or "UndirectedGraph"
    <Flag>      = "0" or "1"

Input File Format
----------------
First line: 
    numVertices numEdges

Each subsequent line:
    EdgeIndex VertexU VertexV Weight
