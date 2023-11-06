

#include <unistd.h>
#include "Utils.h"
#include "Queue.h"
#include "Stack.h"
#include "Algorithm-BFS.h"


void BFS(Building* pBuilding, int startRoomIdx)
{
    
    int totalRooms = pBuilding->nVexNum;
    int Distance[totalRooms];
    int RoomFrom[totalRooms];
    bool visited[totalRooms];
    for(int i=0; i<totalRooms; i++){
        Distance[i] = 999;
        RoomFrom[i] = -1;
        visited[i] = false;
    }
    
    Distance[startRoomIdx] = 0;
    visited[startRoomIdx] = true;

    SqQueue queue;
    queueInit(&queue);
    queuePush(&queue, startRoomIdx);
    queuePrint(queue);

    while(!queueEmpty(queue)){
        ElemType popRoomIdx = queuePop(&queue);
        printf("————————————————————————\n");
        queuePrint(queue);
        // The first ArcNode of each Room
        ArcNode* pCurArc = pBuilding->pRoomList[popRoomIdx].pFirstArc;
        // Travel the ArcNode list of the Room
        while(pCurArc){
            int curVisitRoomIdx = pCurArc->adjVexIdx;
            if(!visited[curVisitRoomIdx]){
                RoomFrom[curVisitRoomIdx] = popRoomIdx;
                Distance[curVisitRoomIdx] = Distance[popRoomIdx]+1;
                visited[curVisitRoomIdx]  = true;

                queuePush(&queue, curVisitRoomIdx);
                queuePrint(queue);
                queuePrint(queue);

                // sleep(1);
            }
            pCurArc = pCurArc->pNextArc;
        }
    }

    int chargerIdx = getRoomIdx(pBuilding, "Charger");
    for(int i=0; i<totalRooms; i++)
        printf("visited[%d]: %s, Distance[%d]: %d, RoomFrom[%d]: %d\n", 
            i, visited[i] == true ? "true" : "false", 
            i, Distance[i], 
            i, RoomFrom[i]);

    pathPrint(pBuilding, Distance, RoomFrom, startRoomIdx, chargerIdx);
}


