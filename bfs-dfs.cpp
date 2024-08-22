/*Breadth-First Search (BFS) and Depth-First Search (DFS) Explained
Breadth-First Search (BFS):

Definition: BFS is an algorithm for traversing or searching tree or graph data structures. It starts at the root (or an arbitrary node) and explores the neighbor nodes at the present depth level before moving on to nodes at the next depth level.
Use Cases: BFS is useful for finding the shortest path in unweighted graphs, level-order traversal of trees, etc.
Depth-First Search (DFS):

Definition: DFS is an algorithm for traversing or searching tree or graph data structures. It starts at the root (or an arbitrary node) and explores as far as possible along each branch before backtracking.
Use Cases: DFS is useful for pathfinding, topological sorting, detecting cycles in graphs, etc.
BFS and DFS: C++ Implementations
Version 1: User Input for Graph Creation*/

#include <iostream>
#include <list>
#include <queue> // Required for BFS

// Graph class represents a directed graph using adjacency list representation
class Graph {
    int V; // Number of vertices
    std::list<int> *adj; // Pointer to an array containing adjacency lists

public:
    // Constructor: initialize the graph with V vertices
    Graph(int V) {
        this->V = V;
        adj = new std::list<int>[V];
    }

    // Function to add an edge to the graph
    void addEdge(int v, int w) {
        adj[v].push_back(w); // Add w to v's list
    }

    // Function to perform BFS starting from a given source vertex
    void BFS(int s) {
        // Mark all the vertices as not visited
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        // Create a queue for BFS
        std::queue<int> queue;

        // Mark the current node as visited and enqueue it
        visited[s] = true;
        queue.push(s);

        while (!queue.empty()) {
            // Dequeue a vertex from the queue and print it
            s = queue.front();
            std::cout << s << " ";
            queue.pop();

            // Get all adjacent vertices of the dequeued vertex s
            // If an adjacent vertex has not been visited, mark it visited and enqueue it
            for (auto adjVertex : adj[s]) {
                if (!visited[adjVertex]) {
                    visited[adjVertex] = true;
                    queue.push(adjVertex);
                }
            }
        }

        // Clean up
        delete[] visited;
    }

    // Function to perform DFS starting from a given source vertex
    void DFS(int s) {
        // Mark all the vertices as not visited
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        // Call the recursive helper function to perform DFS traversal
        DFSUtil(s, visited);

        // Clean up
        delete[] visited;
    }

    // A function used by DFS to recursively visit vertices
    void DFSUtil(int v, bool visited[]) {
        // Mark the current node as visited and print it
        visited[v] = true;
        std::cout << v << " ";

        // Recur for all vertices adjacent to this vertex
        for (auto adjVertex : adj[v]) {
            if (!visited[adjVertex]) {
                DFSUtil(adjVertex, visited);
            }
        }
    }
};

int main() {
    int V, E, v, w, startVertex;

    // Input number of vertices and edges
    std::cout << "Enter number of vertices: ";
    std::cin >> V;
    std::cout << "Enter number of edges: ";
    std::cin >> E;

    Graph g(V);

    // Input edges
    for (int i = 0; i < E; i++) {
        std::cout << "Enter edge (v w): ";
        std::cin >> v >> w;
        g.addEdge(v, w);
    }

    // Input starting vertex for BFS and DFS
    std::cout << "Enter starting vertex for BFS: ";
    std::cin >> startVertex;
    std::cout << "BFS starting from vertex " << startVertex << ":\n";
    g.BFS(startVertex);
    std::cout << std::endl;

    std::cout << "Enter starting vertex for DFS: ";
    std::cin >> startVertex;
    std::cout << "DFS starting from vertex " << startVertex << ":\n";
    g.DFS(startVertex);
    std::cout << std::endl;

    return 0;
}
/* Explanation:
Graph Class:

Represents a graph using an adjacency list.
V represents the number of vertices.
adj is an array of lists to store adjacent vertices for each vertex.
addEdge Function:

Adds a directed edge from vertex v to vertex w.
BFS Function:

Uses a queue to explore each level of the graph, starting from a given source vertex.
Marks visited vertices to avoid revisiting them.
DFS Function:

Recursively explores as far as possible along each branch before backtracking.
Uses a helper function DFSUtil for recursion.
Main Function:

Allows user input to create a graph and perform BFS and DFS.
---------------------------------------------------------------
Version 2: Predefined Graph in Main Function*/


#include <iostream>
#include <list>
#include <queue>

// Graph class represents a directed graph using adjacency list representation
class Graph {
    int V; // Number of vertices
    std::list<int> *adj; // Pointer to an array containing adjacency lists

public:
    // Constructor: initialize the graph with V vertices
    Graph(int V) {
        this->V = V;
        adj = new std::list<int>[V];
    }

    // Function to add an edge to the graph
    void addEdge(int v, int w) {
        adj[v].push_back(w); // Add w to v's list
    }

    // Function to perform BFS starting from a given source vertex
    void BFS(int s) {
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        std::queue<int> queue;

        visited[s] = true;
        queue.push(s);

        while (!queue.empty()) {
            s = queue.front();
            std::cout << s << " ";
            queue.pop();

            for (auto adjVertex : adj[s]) {
                if (!visited[adjVertex]) {
                    visited[adjVertex] = true;
                    queue.push(adjVertex);
                }
            }
        }

        delete[] visited;
    }

    // Function to perform DFS starting from a given source vertex
    void DFS(int s) {
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        DFSUtil(s, visited);

        delete[] visited;
    }

    void DFSUtil(int v, bool visited[]) {
        visited[v] = true;
        std::cout << v << " ";

        for (auto adjVertex : adj[v]) {
            if (!visited[adjVertex]) {
                DFSUtil(adjVertex, visited);
            }
        }
    }
};

int main() {
    // Predefined graph with 5 vertices
    Graph g(5);

    // Adding edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    // Perform BFS starting from vertex 0
    std::cout << "BFS starting from vertex 0:\n";
    g.BFS(0);
    std::cout << std::endl;

    // Perform DFS starting from vertex 0
    std::cout << "DFS starting from vertex 0:\n";
    g.DFS(0);
    std::cout << std::endl;

    return 0;
}
/*
Explanation:
This version of the code uses a predefined graph:

Predefined Graph:

The graph is created with 5 vertices.
Edges are added manually to form a simple structure.
Main Function:

Directly performs BFS and DFS starting from vertex 0.
This version is useful when you want to test or demonstrate the algorithms without user input.
Summary:
BFS: Explores the graph level by level, using a queue to manage the vertices.
DFS: Explores as far as possible along each branch, using recursion or a stack.
Understanding both algorithms and their implementations is crucial for your exam. 
Practice by writing and running these codes, and try variations by modifying the graph structure to reinforce your understanding.*/








