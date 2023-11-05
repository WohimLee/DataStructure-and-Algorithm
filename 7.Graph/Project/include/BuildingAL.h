#ifndef BUILDING_AL_H
#define BUILDING_AL_H

/* Adjacency List */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ROOM_NUM 100
#define BUFFER_SIZE 64 // Adjust as necessary for the longest line

typedef struct ArcNode
{
    int adjVexIdx; 
    struct ArcNode* pNextArc;
}ArcNode;


typedef struct VexNode
{
    int nNodeIdx;
    char cRoomType[16];
    char cDescription[8];
    ArcNode* pFirstArc;
    int nArcs[16];
    int nArcCount;
}Room, RoomList[MAX_ROOM_NUM];


typedef struct ALGraph
{
    RoomList pRoomList;
    int nVexNum;
    int nArcNum;
}Building;


Building* createBuilding();

void initBuilding(Building* pBuilding);

void processCSVRow(char* line, Building* pBuilding, int vexIdx);

ArcNode* initFirstArc(int adjVexIdx);

void insertArc(ArcNode* pFirstArc, int arcIdx, int tokenVexIdx);


void printArcList(Room* pRoom);




#endif // BUILDING_AL_H