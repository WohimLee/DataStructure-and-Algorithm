#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TOTAL_ROOMS 78

typedef struct Node {
    int roomIndex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numRooms;
    Node** adjLists;
    char** roomNames;
} Graph;

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->numRooms = vertices;

    graph->adjLists = malloc(vertices * sizeof(Node*));
    graph->roomNames = malloc(vertices * sizeof(char*));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->roomNames[i] = NULL;
    }

    return graph;
}

int getRoomIndex(Graph* graph, const char* roomName) {
    for (int i = 0; i < graph->numRooms; i++) {
        if (graph->roomNames[i] && strcmp(graph->roomNames[i], roomName) == 0) {
            return i;
        }
    }
    return -1;
}

void addRoomName(Graph* graph, const char* roomName) {
    for (int i = 0; i < graph->numRooms; i++) {
        if (!graph->roomNames[i]) {
            graph->roomNames[i] = strdup(roomName);
            break;
        }
    }
}

void addEdge(Graph* graph, const char* src, const char* dest) {
    if (getRoomIndex(graph, src) == -1) {
        addRoomName(graph, src);
    }
    if (getRoomIndex(graph, dest) == -1) {
        addRoomName(graph, dest);
    }

    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->roomIndex = getRoomIndex(graph, dest);
    newNode->next = graph->adjLists[getRoomIndex(graph, src)];
    graph->adjLists[getRoomIndex(graph, src)] = newNode;
    
    // For undirected graph
    newNode = (Node*) malloc(sizeof(Node));
    newNode->roomIndex = getRoomIndex(graph, src);
    newNode->next = graph->adjLists[getRoomIndex(graph, dest)];
    graph->adjLists[getRoomIndex(graph, dest)] = newNode;
}

int main() {
    Graph* building = createGraph(TOTAL_ROOMS);

    // Construct the graph based on the building's description
    addEdge(building, "Lift1", "Lift2");
    addEdge(building, "Lift1", "Lobby1");
    addEdge(building, "Lift1", "Charger");
    addEdge(building, "Lift2", "Lift3");
    addEdge(building, "Lift2", "Lobby2");
    // ... Continue for all rooms and their connections

    return 0;
}
