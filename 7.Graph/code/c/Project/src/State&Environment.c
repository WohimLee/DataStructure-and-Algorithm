#include "BuildingAL.h"



Building* createBuilding()
{
    Building* pBuilding = (Building*)malloc(sizeof(Building));
    if(!pBuilding){
        printf("Creat Building Failed!\n");
        return NULL;
    }
    pBuilding->nVexNum = 0;
    pBuilding->nArcNum = 0;
    return pBuilding;
}

void insertArc(ArcNode* pFirstArc, int arcIdx, int tokenVexIdx)
{
    // if(arcIdx < 1)
    //     return;
    if(arcIdx == 1){
        ArcNode* pTemp = (ArcNode*)malloc(sizeof(ArcNode));
        pTemp->adjVexIdx = tokenVexIdx;
        pTemp->pNextArc = pFirstArc->pNextArc;
        pFirstArc->pNextArc = pTemp;
        return;
    }
    ArcNode* pCurArc = pFirstArc;
    int curArcIdx = 0;
    while(pCurArc != NULL && curArcIdx < arcIdx-1)
    {
        pCurArc = pCurArc->pNextArc;
        curArcIdx++;
    }
    if(pCurArc == NULL){
        printf("It is the last Arc.\n");
        return;
    }
    ArcNode* pTemp = (ArcNode*)malloc(sizeof(ArcNode));
    pTemp->adjVexIdx = tokenVexIdx;
    pTemp->pNextArc = pCurArc->pNextArc;
    pCurArc->pNextArc = pTemp;
}

ArcNode* initFirstArc(int adjVexIdx)
{
    ArcNode* pFirstArc = (ArcNode*)malloc(sizeof(ArcNode));
    if(!pFirstArc)
        printf("Init ArcList Failed!\n");
    pFirstArc->adjVexIdx = adjVexIdx;
    pFirstArc->pNextArc = NULL;
    return pFirstArc;
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
        strncpy(pBuilding->pRoomList[vexIdx].cRoomType, token, sizeof(pBuilding->pRoomList[vexIdx].cRoomType));
        token = strtok(NULL, ",");
    }

    if(token != NULL){
        strncpy(pBuilding->pRoomList[vexIdx].cDescription, token, sizeof(pBuilding->pRoomList[vexIdx].cDescription));
        token = strtok(NULL, ",");
    }

    int arcIdx = 0;
    while(token != NULL){
        int tokenVexIdx = atoi(token);
        pBuilding->pRoomList[vexIdx].nArcs[arcIdx] = tokenVexIdx;
        if(arcIdx == 0){
            pBuilding->pRoomList[vexIdx].pFirstArc = initFirstArc(tokenVexIdx);
        }
        else{
            insertArc(pBuilding->pRoomList[vexIdx].pFirstArc, arcIdx, tokenVexIdx);
        }
        token = strtok(NULL, ",");
        arcIdx++;
    }
    pBuilding->pRoomList[vexIdx].nArcCount = arcIdx;
}


void printArcList(Room* pRoom)
{
    ArcNode* pCurArc = pRoom->pFirstArc;
    printf("Arcs: ");
    while(pCurArc)
    {
        printf("%d ", pCurArc->adjVexIdx);
        pCurArc = pCurArc->pNextArc;
    }
    printf("\n");
}


void initBuilding(Building* pBuilding)
{
    char buffer[BUFFER_SIZE];
    FILE* file;

    file = fopen("./workspace/BuildingMap.csv", "r");
    if(!file){
        perror("Failed to open file!\n");
        return;
    }
    int NodeIdx = 0;
    while(fgets(buffer, BUFFER_SIZE, file)){
        buffer[strcspn(buffer, "\n\r")] = 0; // confirm the effective conntents
        processCSVRow(buffer, pBuilding, NodeIdx);
        printf("RoomIdx: %d\nRoom Type: %s\nDescription: %s\n",
               pBuilding->pRoomList[NodeIdx].nNodeIdx, 
               pBuilding->pRoomList[NodeIdx].cRoomType,
               pBuilding->pRoomList[NodeIdx].cDescription
               );
        // printArcList(&pBuilding->pRoomList[NodeIdx]);
        ArcNode* pCurArc = pBuilding->pRoomList[NodeIdx].pFirstArc;
        printf("Arcs: ");
        while(pCurArc)
        {
            printf("%d ", pCurArc->adjVexIdx);
            pCurArc = pCurArc->pNextArc;
        }

        printf("\n\n");
        NodeIdx++;
    }
    fclose(file);
    pBuilding->nVexNum = NodeIdx;
}


int getRoomIdx(Building* pBuilding, const char* sDescription)
{
    for(int i=0; i<MAX_ROOM_NUM; i++){
        int res = strcmp(pBuilding->pRoomList[i].cDescription, sDescription);
        if(res == 0)
            return i;
    }
    return -1;
}