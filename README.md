# Graph Operations

A C++ project implementing Dijkstra's algorithm using custom data structures (graph, min-heap, and stack). 
This project efficiently computes shortest paths in a graph using a priority queue-based approach. 
It is useful for applications such as network routing, navigation systems, and logistics optimization.

## File Structure

- `data_structures.h`: Data type definitions.
- `graph.h / graph.cpp`: Graph creation, edge insertion, and Dijkstra's algorithm.
- `heap.h / heap.cpp`: Min-heap implementation for efficient shortest path calculations.
- `stack.h / stack.cpp`: Stack operations for path reconstruction.
- `util.h / util.cpp`: Command-line parsing and file I/O utilities.
- `main.h / main.cpp`: Main program and instruction processing.

## Compilation

To compile the project, run:

make

## Usage

./PJ3 <INPUT_FILE> <GRAPH_TYPE> <FLAG>

- `<InputFile>` = Path to the graph data file.
- `<GraphType>` = `"DirectedGraph"` or `"UndirectedGraph"`.
- `<Flag>` = `"0"` or `"1"`.

## Input File Format

The input file should contain the number of vertices and edges in the first line, followed by edge definitions.

<numVertices> <numEdges>  

<VertexU> <VertexV> <Weight>

### Example Input (`graph_input.txt`):

5 7  
0 1 4  
0 2 1  
1 3 2  
2 1 2  
2 3 5  
3 4 1  
4 0 7  

### Example Output (`SingleSource 0` Command):

Vertex 0 → Vertex 1: 3  
Vertex 0 → Vertex 2: 1  
Vertex 0 → Vertex 3: 5  
Vertex 0 → Vertex 4: 6  

## Available Commands

- **Stop**: Terminates the program.
- **PrintADJ**: Prints the adjacency list of the graph.
- **SinglePair**: Computes and prints the shortest path from a source vertex to a destination vertex.
- **SingleSource**: Computes and prints shortest paths from a single source to all reachable vertices.
- **PrintLength**: Prints the length of the shortest path between two vertices.
- **PrintPath**: Prints the actual shortest path between two vertices.

## Technologies Used

- **C++**
- **Custom Data Structures** (Adjacency List, Min-Heap, Stack)
- **g++ Compilation** with Makefile

## Use Cases

This project can be used for:
- **Network Routing:** Finding optimal paths in computer networks.
- **Navigation Systems:** Calculating shortest travel routes.
- **Logistics Optimization:** Determining the best paths for deliveries and transportation planning.
