# ShortestPathAlgorithm Project

A C++ project implementing Dijkstra's algorithm using custom data structures (graph, min-heap, and stack).

## File Structure
- **data_structures.h**: Data type definitions.
- **graph.h / graph.cpp**: Graph creation, edge insertion, and Dijkstra's algorithm.
- **heap.h / heap.cpp**: Min-heap implementation.
- **stack.h / stack.cpp**: Stack operations for path reconstruction.
- **util.h / util.cpp**: Command-line parsing and file I/O utilities.
- **main.h / main.cpp**: Main program and instruction processing.

## Compilation
```bash
g++ -o PJ3 main.cpp heap.cpp graph.cpp stack.cpp util.cpp -std=c++11
Usage
bash
Copy
./PJ3 <InputFile> <GraphType> <Flag>
InputFile: Path to the graph data file.
GraphType: Either DirectedGraph or UndirectedGraph.
Flag: Either 0 or 1.
Input File Format
First line: <numVertices> <numEdges>
Each subsequent line: <EdgeIndex> <VertexU> <VertexV> <Weight>

Example
Given an input file graph.txt with the following content:

Copy
5 7
1 1 2 3.5
2 1 3 2.1
3 2 3 1.2
4 2 4 4.0
5 3 4 2.5
6 3 5 3.0
7 4 5 1.8
You can run the program with:

bash
Copy
./PJ3 graph.txt UndirectedGraph 1
