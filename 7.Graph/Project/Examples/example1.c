
#include <stdio.h>

#include "Common.h"
#include "Building.h"



int main(int argc, char** argv)
{

    Building* pBuilding = createBuilding();
    initRoomList(pBuilding);
    int index = 78;
    printf("Room %d is: %s, room index: %d\n", 
        index, pBuilding->pRoomList[index].cRoomType, pBuilding->pRoomList[index].iRoomIdx);
    // printRoomInfo(pBuilding->pRoomList[index].info);
    printf("Room %d info: %c%d.%d\n", 
        pBuilding->pRoomList[index].iRoomIdx,
        pBuilding->pRoomList[index].info.alphabet,
        pBuilding->pRoomList[index].info.floor,
        pBuilding->pRoomList[index].info.type);


    return 0;
}