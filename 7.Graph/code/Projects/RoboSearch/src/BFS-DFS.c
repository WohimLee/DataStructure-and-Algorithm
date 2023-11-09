

#include <unistd.h>
#include "System.h"
#include "Queue.h"
#include "Stack.h"
#include "BFS-DFS.h"

int Distance[MAX_ROOM_NUM];
int RoomFrom[MAX_ROOM_NUM];
bool visited[MAX_ROOM_NUM];


void breadthFirstSearch(Building* pBuilding, int startStateIdx)
{
    
    int totalRooms = pBuilding->nNodeNum;
    for(int i=0; i<totalRooms; i++){
        Distance[i] = 999;
        RoomFrom[i] = -1;
        visited[i] = false;
    }
    
    Distance[startStateIdx] = 0;
    visited[startStateIdx] = true;

    Queue queue;
    queueInit(&queue);
    queuePush(&queue, startStateIdx);
    queuePrint(queue);

    while(!queueEmpty(queue)){
        ElemType popRoomIdx = queuePop(&queue);
        printf("\nPop the head element: %d,  ", popRoomIdx);
        displayCurrentLocation(pBuilding, popRoomIdx);
        printf("——————————————————————————————————————————————\n");
        
        queuePrint(queue);
        // The first ArcNode of each Room
        Action* pCurArc = pBuilding->pRoomList[popRoomIdx].pFirstEdge;
        // Travel the ArcNode list of the Room
        while(pCurArc){
            int curVisitRoomIdx = pCurArc->adjNodeIdx;
            if(!visited[curVisitRoomIdx]){
                RoomFrom[curVisitRoomIdx] = popRoomIdx;
                Distance[curVisitRoomIdx] = Distance[popRoomIdx]+1;
                visited[curVisitRoomIdx]  = true;

                queuePush(&queue, curVisitRoomIdx);
                printf("\nPush %d in queue\n", curVisitRoomIdx);
                queuePrint(queue);

                // sleep(1);
            }
            pCurArc = pCurArc->pNextEdge;
        }
    }
    // int chargerIdx = getRoomIdx(pBuilding, "Charger");
    // for(int i=0; i<totalRooms; i++)
    //     printf("visited[%d]: %s, Distance[%d]: %d, RoomFrom[%d]: %d\n", 
    //         i, visited[i] == true ? "true" : "false", 
    //         i, Distance[i], 
    //         i, RoomFrom[i]);
}


void depthFirstSearch(Building* pBuilding, int startStateIdx)
{
    int totalRooms = pBuilding->nNodeNum;
    for(int i=0; i<totalRooms; i++){
        Distance[i] = 999;
        RoomFrom[i] = -1;
        visited[i] = false;
    }
    Distance[startStateIdx] = 0;
    visited[startStateIdx] = true;

    Stack* pStack = stackInit();
    stackPush(pStack, startStateIdx);
    stackPrint(*pStack);

    while(!stackEmpty(*pStack))
    {
        ElemType popRoomIdx = stackPop(pStack);
        printf("\nPop the top element: %d, ", 
            popRoomIdx);
        displayCurrentLocation(pBuilding, popRoomIdx);
        printf("——————————————————————————————————————————————\n");
        stackPrint(*pStack);

        Action* pCurArc = pBuilding->pRoomList[popRoomIdx].pFirstEdge;
        while(pCurArc)
        {
            int curVisitRoomIdx = pCurArc->adjNodeIdx;
            if(!visited[curVisitRoomIdx]){
                RoomFrom[curVisitRoomIdx] = popRoomIdx;
                Distance[curVisitRoomIdx] = Distance[popRoomIdx]+1;
                visited[curVisitRoomIdx]  = true;

                stackPush(pStack, curVisitRoomIdx);
                printf("\nPush %d in stack\n", curVisitRoomIdx);

                stackPrint(*pStack);

                // sleep(1);
            }
            pCurArc = pCurArc->pNextEdge;
        }
    }
}

void displayCurrentLocation(Building* pBuilding, int popRoomIdx)
{
    printf("HOOVI is now at %s\n", 
        pBuilding->pRoomList[popRoomIdx].sState);
}

void tracePathBack(Building* pBuilding, int startRoomIdx)
{
    int chargerIdx = getRoomIdx(pBuilding, "Charger");
    int minDis = Distance[chargerIdx];
    printf("\n\nFrom Room %s to %s Room: \n", 
        pBuilding->pRoomList[startRoomIdx].sState,
        pBuilding->pRoomList[chargerIdx].sState);
    printf("————————————————————————————————\n");
    printf("%5s| The shortest distance: %d\n", "", minDis);

    printf("%5s| The shortest path: ", "");
    Stack* pStack = stackInit();
    stackPush(pStack, chargerIdx);
    int roomFromIdx = RoomFrom[chargerIdx];
    // stackPush(pStack, roomFromIdx);

    while(roomFromIdx != -1){
        stackPush(pStack, roomFromIdx);
        roomFromIdx = RoomFrom[roomFromIdx];

    }
    
    int size = stackSize(*pStack);
    for(int i=0; i<size-1; i++)
        printf("%d -> ", stackPop(pStack));
    printf("%d\n\n", stackPop(pStack));
}