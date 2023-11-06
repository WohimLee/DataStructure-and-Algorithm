

#include "Utils.h"
#include "Stack.h"

void messagePrint(Building* pBuilding)
{
    printf("Enter a room where you wanna place HOOVI? Choose one of the following descriptions: \n\n");
    int floor = 0;
    int i = 0; // Index for the array

    // Process until we reach the sentinel value
    while(i < MAX_ROOM_NUM, floor<3) {
        printf("| The %d floor:\n", floor);
        printf("————————————————————————————————\n%5s", "");


        // Print 'Lift-x' and 'Lobby-x'
        printf("| %-8s%-8s\n",
            pBuilding->pRoomList[i].cDescription, 
            pBuilding->pRoomList[i+1].cDescription);
        i += 2; // Move past 'Lift-x' and 'Lobby-x'

        // Assuming there are always 14 rooms per sub-section
        printf("%5s| ", "");
        for (int j = 0; j < 12; j++, i++) {
            printf("%-8s", pBuilding->pRoomList[i].cDescription);
        }
        printf("\n%5s| ", "");

        // Print the second sub-section of rooms
        for (int j = 0; j < 12; j++, i++) {
            printf("%-8s", pBuilding->pRoomList[i].cDescription);
        }
        printf("\n\n"); // Add extra newline for spacing

        floor++; // Move to the next floor
    }
}

void welcomePrint()
{
    printf("Initialized Building Complete!\n");
    printf("—————————————————————————————————————————————————\n");
    printf(" _       __     __                          __\n");
    printf("| |     / /__  / /________  ____ ___  ___  / /\n");
    printf("| | /| / / _ \\/ / ___/ __ \\/ __ `__ \\/ _ \\/ / \n");
    printf("| |/ |/ /  __/ / /__/ /_/ / / / / / /  __/_/  \n");
    printf("|__/|__/\\___/_/\\___/\\____/_/ /_/ /_/\\___(_)   \n\n\n");
    printf("%48s\n", "By Heqian.Li No.23021010140");
    printf("—————————————————————————————————————————————————\n\n");
    printf("Press \"Enter\" to continue.\n");
}


void pathPrint(Building* pBuilding, int Distance[], int RoomFrom[], int srcIdx, int dstIdx)
{
    int minDis = Distance[dstIdx];
    printf("\n\nFrom Room %s to %s Room: \n", 
        pBuilding->pRoomList[srcIdx].cDescription,
        pBuilding->pRoomList[dstIdx].cDescription);
    printf("————————————————————————————————\n");
    printf("%5s| The shortest distance: %d\n", "", minDis);

    printf("%5s| The shortest path: ", "");
    SqStack* pStack = stackInit();
    stackPush(pStack, dstIdx);
    int roomFromIdx = RoomFrom[dstIdx];
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