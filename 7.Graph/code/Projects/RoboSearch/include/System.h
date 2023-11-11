#ifndef SYSTEM_H
#define SYSTEM_H

#include "Stack.h"
#include "BFS-DFS.h"
#include "State-Environment.h"

#define MAX_ROOM_NUM 100
#define BUFFER_SIZE 64 // Adjust as necessary for the longest line


void welcomeInformation();

int initializeState(Building* Building);

void inputMessage(Building* pBuilding);

void goalTest(Building* pBuilding, bool verbose);


#endif // SYSTEM_H


