#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H



#include <stdio.h>
#include <stdlib.h>

// Define the structure for an adjacency list node
typedef struct AdjListNode {
    int dest;
    struct AdjListNode* next;
} AdjListNode;

// Define the structure for an adjacency list
typedef struct AdjList {
    struct AdjListNode* head;  // Pointer to head node of list
} AdjList;

// Define the structure for a graph. A graph is an array of adjacency lists.
// The size of the array will be the number of vertices in the graph.
typedef struct Graph {
    int numVertices;
    struct AdjList* array;
} Graph;

// Function to create a new adjacency list node
AdjListNode* newAdjListNode(int dest) {
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph of V vertices
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = V;

    // Create an array of adjacency lists. Size of array will be V
    graph->array = (AdjList*)malloc(V * sizeof(AdjList));

    // Initialize each adjacency list as empty by making head as NULL
    for (int i = 0; i < V; ++i) {
        graph->array[i].head = NULL;
    }

    return graph;
}

// Adds an undirected edge to an undirected graph
void addEdge(Graph* graph, int src, int dest) {
    // Add an edge from src to dest. A new node is added to the adjacency
    // list of src. The node is added at the beginning
    AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since graph is undirected, add an edge from dest to src also
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function to print the adjacency list representation of graph
void printGraph(Graph* graph) {
    for (int v = 0; v < graph->numVertices; ++v) {
        AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl) {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}


#endif // ADJACENCY_LIST_H