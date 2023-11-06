#include <string.h>

#include "Utils.h"
#include "State&Environment.h"
#include "BFS&DFS.h"

int main(int argc, char** argv)
{

    Building* pBuilding = createBuilding();
    initBuilding(pBuilding);

    welcomePrint();
    getchar();

    char sStartRoom[8]; // Declare a char array of sufficient size
    printMessage(pBuilding);
    printf("Please enter here: ");

    scanf("%7s", sStartRoom); // Read a string from the user into the array
    int startRoomIdx = getRoomIdx(pBuilding, sStartRoom);

    if(startRoomIdx == -1){
        printf("————————————————————————————————\n%5s", "");
        printf("[INFO]: Your enter: \"%s\", this can't match any room, please check your input.\n", sStartRoom);
        return -1;
    }

    printf("\n————————————————————————————————\n");
    printf("You enter: %s, which means:\n", sStartRoom);
    printf("%5s| RoomIdx: %d\n%5s| Room Type: %s\n%5s| Description: %s\n\n",
               "", pBuilding->pRoomList[startRoomIdx].nNodeIdx, 
               "", pBuilding->pRoomList[startRoomIdx].cRoomType,
               "", pBuilding->pRoomList[startRoomIdx].cDescription
               );
    getchar();
    printf("Do you wanna begin BFS algorithm? Pres enter to continue.\n");
    getchar();

    BFS(pBuilding, startRoomIdx);

    // int startRoomIdx = getRoomIdx(pBuilding, "Lift-1");
    // BFS(pBuilding, startRoomIdx);


    return 0;
}

