#ifndef BUILDING_ENVRIONMENT_H
#define BUILDING_ENVRIONMENT_H

/* Represent the building as Adjacency List Graph*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define MAX_ROOM_NUM 100
#define BUFFER_SIZE 64 // Adjust as necessary for the longest line

typedef struct Edge
{
    int nAdjNodeIdx;         // Index of the adjacent node
    struct Edge* pNextEdge; // Pointer to the next edge
}Action;

typedef struct Node
{
    int nNodeIdx;       // Node index
    int nEdgeNum;       // Number of edges
    int aEdges[16];     // Array of edges (by index)
    Action* pFirstEdge; // Pointer to the first edge in a linked list of edges
    char sRoomType[16]; // Type of the room (as a string)
    char sState[8];     // State of the node (as a string)
}Room, RoomList[MAX_ROOM_NUM];


typedef struct ALGraph
{
    RoomList pRoomList;
    int nNodeNum;
}Building;

// 1. Initialize the environment
Building* initializeBuilding(bool verbose);

// 2. Read building configurations from as .csv file
void processCSVRow(char* line, Building* pBuilding, int vexIdx);

// 3. Initialize the first edge of a node
Action* initFirstEdge(int adjVexIdx);

// 4. Insert an edge to the first edge of a node
void insertEdge(Action* pFirstEdge, int arcIdx, int tokenVexIdx);

// 5. Get the room index of the room list
int getRoomIdx(Building* pBuilding, const char* sDescription);

// 6. Successor function to print the adjacent rooms HOOVI can move to from its current position
void findNextRooms(Room* pRoom);


#endif // BUILDING_ENVRIONMENT_H