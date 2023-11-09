#include <string.h>

#include "System.h"
#include "State-Environment.h"
#include "BFS-DFS.h"

int main(int argc, char** argv)
{

    // Welcoming information of the program
    welcomeInformation();

    // Initialize the buiding map
    Building* pBuilding = initializeBuilding(pBuilding);
    
    // // Enter the initial state of the HOOVI
    // int startRoomIdx = initializeState(pBuilding);
    
    // // Choose BFS or DFS
    // int choice;
    // printf("Which algorithm you wanna choose?\n");
    // printf("—————————————————————————————————\n\n");
    // printf("%5s| 1. BFS (Breadth First Search)\n", "");
    // printf("%5s| 2. DFS (Depth First Search)\n\n", "");
    // printf("Enter your choice (1 or 2): ");
    // scanf("%d", &choice);
    
    // switch(choice){
    //     case 1:
    //         breadthFirstSearch(pBuilding, startRoomIdx);
    //         break;
    //     case 2:
    //         depthFirstSearch(pBuilding, startRoomIdx);
    //         break;
    //     default:
    //         printf("Invalid choice!\n");
    // }

    depthFirstSearch(pBuilding, 68);

    tracePathBack(pBuilding, 68);

    return 0;
}

