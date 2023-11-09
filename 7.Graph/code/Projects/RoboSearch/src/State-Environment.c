
#include "State-Environment.h"



Building* initializeBuilding()
{
    Building* pBuilding = (Building*)malloc(sizeof(Building));
    if(!pBuilding){
        printf("Creat Building Failed!\n");
        return NULL;
    }
    pBuilding->nNodeNum = 0;

    char buffer[BUFFER_SIZE];
    FILE* file;

    file = fopen("./workspace/BuildingMap.csv", "r");
    if(!file){
        perror("Failed to open file!\n");
        return NULL;
    }
    int NodeIdx = 0;
    while(fgets(buffer, BUFFER_SIZE, file)){
        buffer[strcspn(buffer, "\n\r")] = 0; // confirm the effective conntents
        processCSVRow(buffer, pBuilding, NodeIdx);
        printf("RoomIdx: %d, RoomType: %s\n%2s| State: %s\n",
               pBuilding->pRoomList[NodeIdx].nNodeIdx, 
               pBuilding->pRoomList[NodeIdx].sRoomType,
               "",
               pBuilding->pRoomList[NodeIdx].sState
               );
        // printArcList(&pBuilding->pRoomList[NodeIdx]);
        Action* pCurArc = pBuilding->pRoomList[NodeIdx].pFirstEdge;
        printf("%2s| Actions: ", "");
        while(pCurArc)
        {
            printf("%d ", pCurArc->adjNodeIdx);
            pCurArc = pCurArc->pNextEdge;
        }

        printf("\n\n");
        NodeIdx++;
    }
    fclose(file);
    pBuilding->nNodeNum = NodeIdx;

    printf("Initialized Building (Adjacency List Graph) Complete!\n");
    printf("—————————————————————————————————————————————————————\n\n");
    printf("Press \"Enter\" to continue...\n\n");
    getchar();

    return pBuilding;
}


void processCSVRow(char* line, Building* pBuilding, int vexIdx)
{
    char* token;
    token = strtok(line, ",");
    if(token != NULL){
        pBuilding->pRoomList[vexIdx].nNodeIdx = atoi(token);
        token = strtok(NULL, ",");
    }

    if(token != NULL){
        strncpy(pBuilding->pRoomList[vexIdx].sRoomType, token, sizeof(pBuilding->pRoomList[vexIdx].sRoomType));
        token = strtok(NULL, ",");
    }

    if(token != NULL){
        strncpy(pBuilding->pRoomList[vexIdx].sState, token, sizeof(pBuilding->pRoomList[vexIdx].sState));
        token = strtok(NULL, ",");
    }

    int arcIdx = 0;
    while(token != NULL){
        int tokenNodeIdx = atoi(token);
        pBuilding->pRoomList[vexIdx].aEdges[arcIdx] = tokenNodeIdx;
        if(arcIdx == 0){
            pBuilding->pRoomList[vexIdx].pFirstEdge = initFirstEdge(tokenNodeIdx);
        }
        else{
            insertEdge(pBuilding->pRoomList[vexIdx].pFirstEdge, arcIdx, tokenNodeIdx);
        }
        token = strtok(NULL, ",");
        arcIdx++;
    }
    pBuilding->pRoomList[vexIdx].nEdgeNum = arcIdx;
}


Action* initFirstEdge(int adjNodeIdx)
{
    Action* pFirstEdge = (Action*)malloc(sizeof(Action));
    if(!pFirstEdge)
        printf("Init ArcList Failed!\n");
    pFirstEdge->adjNodeIdx = adjNodeIdx;
    pFirstEdge->pNextEdge = NULL;
    return pFirstEdge;
}


void insertEdge(Action* pFirstEdge, int arcIdx, int tokenNodeIdx)
{
    // if(arcIdx < 1)
    //     return;
    if(arcIdx == 1){
        Action* pTemp = (Action*)malloc(sizeof(Action));
        pTemp->adjNodeIdx = tokenNodeIdx;
        pTemp->pNextEdge = pFirstEdge->pNextEdge;
        pFirstEdge->pNextEdge = pTemp;
        return;
    }
    Action* pCurArc = pFirstEdge;
    int curArcIdx = 0;
    while(pCurArc != NULL && curArcIdx < arcIdx-1)
    {
        pCurArc = pCurArc->pNextEdge;
        curArcIdx++;
    }
    if(pCurArc == NULL){
        printf("It is the last Arc.\n");
        return;
    }
    Action* pTemp = (Action*)malloc(sizeof(Action));
    pTemp->adjNodeIdx = tokenNodeIdx;
    pTemp->pNextEdge = pCurArc->pNextEdge;
    pCurArc->pNextEdge = pTemp;
}



void findNextRooms(Room* pState)
{
    Action* pCurArc = pState->pFirstEdge;
    printf("Arcs: ");
    while(pCurArc)
    {
        printf("%d ", pCurArc->adjNodeIdx);
        pCurArc = pCurArc->pNextEdge;
    }
    printf("\n");
}



int getRoomIdx(Building* pBuilding, const char* sState)
{
    for(int i=0; i<MAX_ROOM_NUM; i++){
        int res = strcmp(pBuilding->pRoomList[i].sState, sState);
        if(res == 0)
            return i;
    }
    return -1;
}


