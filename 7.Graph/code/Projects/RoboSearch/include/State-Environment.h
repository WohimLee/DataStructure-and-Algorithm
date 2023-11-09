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
    int adjNodeIdx; 
    struct Edge* pNextEdge;
}Action;

typedef struct Node
{
    int nNodeIdx;
    int nEdgeNum;
    int aEdges[16];
    Action* pFirstEdge;
    char sRoomType[16];
    char sState[8];
}Room, RoomList[MAX_ROOM_NUM];


typedef struct ALGraph
{
    RoomList pRoomList;
    int nNodeNum;
}Building;

// 1. Initialize the environment
Building* initializeBuilding();

// 2. Read building configurations from as .csv file
void processCSVRow(char* line, Building* pBuilding, int vexIdx);

// 3. Initialize the first edge of a node
Action* initFirstEdge(int adjVexIdx);

// 4.
void insertEdge(Action* pFirstArc, int arcIdx, int tokenVexIdx);


// 
int getRoomIdx(Building* pBuilding, const char* sDescription);
// 
void findNextRooms(Room* pState);




#endif // BUILDING_ENVRIONMENT_H