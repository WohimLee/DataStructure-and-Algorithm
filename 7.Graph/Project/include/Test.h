#ifndef TEST_H
#define TEST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for each node in the adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Define the structure for the graph
typedef struct Graph {
    int numVertices;
    Node** adjLists;  // Array of pointers
    bool* visited;
} Graph;

// Function to create a node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjLists = (Node**)malloc(vertices * sizeof(Node*));
    graph->visited = (bool*)malloc(vertices * sizeof(bool));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = false;
    }

    return graph;
}

// Function to add edge
void addEdge(Graph* graph, int src, int dest) {
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src for undirected graph
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function for Breadth First Search
void BFS(Graph* graph, int startVertex) {
    // Create a queue
    int* queue = (int*)malloc(graph->numVertices * sizeof(int));

    // Initialize the queue
    int front = 0;
    int rear = -1;

    // Mark the current node as visited and enqueue it
    graph->visited[startVertex] = true;
    queue[++rear] = startVertex;

    while (front <= rear) {
        // Dequeue a vertex
        int currentVertex = queue[front++];

        printf("Visited %d\n", currentVertex);

        // Visit the nodes adjacent to the current node
        Node* temp = graph->adjLists[currentVertex];

        while (temp) {
            int adjVertex = temp->vertex;

            if (!graph->visited[adjVertex]) {
                graph->visited[adjVertex] = true;
                queue[++rear] = adjVertex;
            }
            temp = temp->next;
        }
    }

    free(queue);
}



#endif // TEST_H