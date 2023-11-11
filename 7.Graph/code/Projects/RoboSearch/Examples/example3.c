void findNextRooms(Building* pBuilding, int nNodeIdx)
{
    
    Action* pCurArc = pBuilding->pRoomList[nNodeIdx].pFirstEdge;
    while(pCurArc)
    {
        printf("%s ", pBuilding->pRoomList[nNodeIdx].sState);
        pCurArc = pCurArc->pNextEdge;
    }
    printf("\n\n");
}
