#ifndef BFS_DFS_H
#define BFS_DFS_H

#include <stdbool.h>
#include "State-Environment.h"

bool visitied[MAX_ROOM_NUM];

// 1. BFS algorithm
void breadthFirstSearch(Building* pBuilding, int startStateIdx, bool verbose);

// 2. DFS algorithm
void depthFirstSearch(Building* pBuilding, int startStateIdx, bool verbose);

// 3. Display current locate of HOOVI
void displayCurrentLocation(Building* pBuilding, int popRoomIdx);

// 4. Track back the path from the charger to the robot's
//    and print the path from starting point to charger
void tracePathBack(Building* pBuilding, int startRoomIdx);



#endif // BFS_H