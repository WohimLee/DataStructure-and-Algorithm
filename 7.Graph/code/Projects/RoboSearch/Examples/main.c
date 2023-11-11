#include <string.h>

#include "System.h"
#include "State-Environment.h"
#include "BFS-DFS.h"

int main(int argc, char** argv)
{

    // Welcoming information of the program
    welcomeInformation();

    // Choose whether to show detailed informations
    char yesOrno[5];
    bool verbose = true;
    printf("Do you want to show detailed information? (yes or no): ");
    scanf("%4s", yesOrno);
    if(strcmp(yesOrno, "yes") == 0)
        verbose = true;
    else if (strcmp(yesOrno, "no") == 0)
        verbose = false;
    else{
        printf("Invalid input! Use default setting: yes");
    }

    // Initialize the buiding map
    Building* pBuilding = initializeBuilding(verbose);

    // Goal test: N3.2, Lift-2, K1.1
    goalTest(pBuilding, verbose);

    // Enter the initial state of the HOOVI
    int startRoomIdx = initializeState(pBuilding);

    // Choose BFS or DFS
    int choice;
    printf("Which algorithm you wanna choose?\n");
    printf("—————————————————————————————————\n\n");
    printf("%5s| 1. BFS (Breadth First Search)\n", "");
    printf("%5s| 2. DFS (Depth First Search)\n\n", "");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            breadthFirstSearch(pBuilding, startRoomIdx, verbose);
            tracePathBack(pBuilding, startRoomIdx);
            break;
        case 2:
            depthFirstSearch(pBuilding, startRoomIdx, verbose);
            tracePathBack(pBuilding, startRoomIdx);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}

