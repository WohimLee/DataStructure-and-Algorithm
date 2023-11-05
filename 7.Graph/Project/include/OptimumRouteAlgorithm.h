#ifndef OPTIMUM_ROUTE_ALGORITHM_H
#define OPTIMUM_ROUTE_ALGORITHM_H

#include <stdbool.h>
#include "BuildingAL.h"

bool visitied[MAX_ROOM_NUM];

void BFS(Building* pBuilding, int nRoomIdx);

void DeQueue();

void EnQueue();



#endif // OPTIMUM_ROUTE_ALGORITHM_H