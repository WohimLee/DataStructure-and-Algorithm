void depthFirstSearch(Building* pBuilding, int startStateIdx)
{
    int totalRooms = pBuilding->nNodeNum;
    for(int i = 0; i < totalRooms; i++){
        Distance[i] = 999;
        RoomFrom[i] = -1;
        visited[i] = false;
    }
    
    Distance[startStateIdx] = 0;
    visited[startStateIdx] = true;

    Stack stack;
    stackInit(&stack);
    stackPush(&stack, startStateIdx);

    while(!stackEmpty(stack)){
        ElemType roomIdx = stackPop(&stack);
        printf("\nPop the top element: %d, HOOVI is now at %s\n", 
            roomIdx, pBuilding->pRoomList[roomIdx].sState);
        printf("——————————————————————————————————————————————\n");

        // The first ArcNode of each Room
        Action* pCurArc = pBuilding->pRoomList[roomIdx].pFirstEdge;
        // Travel the ArcNode list of the Room
        while(pCurArc){
            int curVisitRoomIdx = pCurArc->adjNodeIdx;
            if(!visited[curVisitRoomIdx]){
                RoomFrom[curVisitRoomIdx] = roomIdx;
                Distance[curVisitRoomIdx] = Distance[roomIdx] + 1;
                visited[curVisitRoomIdx] = true;

                stackPush(&stack, curVisitRoomIdx);

                // sleep(1);
            }
            pCurArc = pCurArc->pNextEdge;
        }
    }
    // Debugging code to display the results can be re-enabled if necessary
}