
#include "System.h"



void welcomeInformation()
{
    printf("—————————————————————————————————————————————————\n");
    printf("%10s*** ROBOSEARCH SYSTEM ***\n", "");
    printf(" _       __     __                          __\n");
    printf("| |     / /__  / /________  ____ ___  ___  / /\n");
    printf("| | /| / / _ \\/ / ___/ __ \\/ __ `__ \\/ _ \\/ / \n");
    printf("| |/ |/ /  __/ / /__/ /_/ / / / / / /  __/_/  \n");
    printf("|__/|__/\\___/_/\\___/\\____/_/ /_/ /_/\\___(_)   \n\n\n");
    printf("%48s\n", "By Heqian.Li No.23021010140");
    printf("—————————————————————————————————————————————————\n\n");
    printf("Press \"Enter\" to continue...\n\n");
    getchar();
}


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
            pBuilding->pRoomList[i].sState, 
            pBuilding->pRoomList[i+1].sState);
        i += 2; // Move past 'Lift-x' and 'Lobby-x'

        // Assuming there are always 14 rooms per sub-section
        printf("%5s| ", "");
        for (int j = 0; j < 12; j++, i++) {
            printf("%-8s", pBuilding->pRoomList[i].sState);
        }
        printf("\n%5s| ", "");

        // Print the second sub-section of rooms
        for (int j = 0; j < 12; j++, i++) {
            printf("%-8s", pBuilding->pRoomList[i].sState);
        }
        printf("\n\n"); // Add extra newline for spacing

        floor++; // Move to the next floor
    }
}


int initializeState(Building* pBuilding)
{
    char sStartRoom[8]; // Declare a char array of sufficient size
    messagePrint(pBuilding);
    printf("Enter the initial state to start from (e.g. C3.2) : ");

    scanf("%7s", sStartRoom); // Read a string from the user into the array
    int startRoomIdx = getRoomIdx(pBuilding, sStartRoom);

    if(startRoomIdx == -1){
        printf("————————————————————————————————————————\n");
        printf("[INFO]: Your enter: \"%s\", this can't match any room, please check your input.\n", sStartRoom);
        return -1;
    }

    printf("—————————————————————————————————————————————————————————\n\n");
    printf("You enter: %s, which means:\n", sStartRoom);
    printf("%5s| RoomIdx: %d, RoomType: %s\n%5s| State: %s\n\n",
               "", pBuilding->pRoomList[startRoomIdx].nNodeIdx, 
               pBuilding->pRoomList[startRoomIdx].sRoomType,
               "", pBuilding->pRoomList[startRoomIdx].sState
               );
    printf("We're going to search the shortest route of:\n");
    printf("————————————————————————————————————————————\n\n");
    printf("%12s%s -> Charger\n\n", "", pBuilding->pRoomList[startRoomIdx].sState);
    printf("————————————————————————————————————————————\n\n");

    printf("Press \"Enter\" to continue...\n\n");
    getchar();
    getchar();

    return startRoomIdx;
}

