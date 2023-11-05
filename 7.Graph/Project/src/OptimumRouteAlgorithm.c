
#include "OptimumRouteAlgorithm.h"


void BFS(Building* pBuilding, int startRoomIdx)
{
    bool visited[MAX_ROOM_NUM] = {false};
    visited[startRoomIdx] = true;

    int queue[MAX_ROOM_NUM];
    int front = 0;
    int rear  = -1;
    queue[++rear] = startRoomIdx;

    while(front <= rear){
        int curRoomIdx = queue[front++];
        printf("Visited %d",
            pBuilding->pRoomList[curRoomIdx])
    }

}

