#ifndef BFS_DFS_H
#define BFS_DFS_H

#include <stdbool.h>
#include "State&Environment.h"

bool visitied[MAX_ROOM_NUM];

void BFS(Building* pBuilding, int nRoomIdx);




#endif // BFS_H