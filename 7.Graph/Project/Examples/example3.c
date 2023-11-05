#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_FLOORS 3
#define NUM_ROOMS_PER_FLOOR 25 // 12 offices + 12 receptions + lobby
#define MAX_QUEUE_SIZE 100

typedef struct {
    char room[10];
    int floor;
} Location;

typedef struct {
    Location path[MAX_QUEUE_SIZE];
    int pathLength;
} Path;

typedef struct {
    Path queue[MAX_QUEUE_SIZE];
    int front, rear;
} PathQueue;

void initializeQueue(PathQueue *q) {
    q->front = q->rear = 0;
}

int isEmpty(PathQueue *q) {
    return q->front == q->rear;
}

int isFull(PathQueue *q) {
    return q->rear == MAX_QUEUE_SIZE;
}

void enqueue(PathQueue *q, Path *path) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    q->queue[q->rear++] = *path;
}

int dequeue(PathQueue *q, Path *path) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return 0;
    }
    *path = q->queue[q->front++];
    return 1;
}

// Check if the location is the charging room
int isChargingRoom(Location *loc) {
    return strcmp(loc->room, "CHARGE") == 0;
}

// Get the possible successors from the current location
void getSuccessors(Location *loc, Location successors[], int *numSuccessors) {
    *numSuccessors = 0;

    // Each floor's lobby has access to the lift and all 12 pairs of reception rooms
    if (loc->room[0] == 'L') {
        for (int i = 1; i <= 12; i++) {
            sprintf(successors[(*numSuccessors)++].room, "K%d.%d", loc->floor, i*2-1);
        }
        sprintf(successors[(*numSuccessors)++].room, "LIFT%d", loc->floor);
    } 
    // From an office, HOOVI can only go back to its reception
    else if (loc->room[0] == 'N' || loc->room[0] == 'K') {
        int officeNum = atoi(&loc->room[2]);
        sprintf(successors[(*numSuccessors)++].room, "K%d.%d", loc->floor, officeNum - 1);
    } 
    // From a reception, HOOVI can go to its office or back to the lobby
    else if (atoi(&loc->room[2]) % 2 != 0) {
        sprintf(successors[(*numSuccessors)++].room, "K%d.%d", loc->floor, atoi(&loc->room[2]) + 1);
        sprintf(successors[(*numSuccessors)++].room, "L%d", loc->floor);
    }
    // From the lift, HOOVI can go to the charging room if it's on the first floor
    // or to the lobbies of the next floors above or below
    else if (loc->room[0] == 'L' && loc->room[1] == 'I') {
        if (loc->floor == 1) {
            strcpy(successors[(*numSuccessors)++].room, "CHARGE");
        }
        if (loc->floor < NUM_FLOORS) {
            sprintf(successors[(*numSuccessors)++].room, "L%d", loc->floor + 1);
        }
        if (loc->floor > 1) {
            sprintf(successors[(*numSuccessors)++].room, "L%d", loc->floor - 1);
        }
    }
    
    // Set the floor for all successors
    for (int i = 0; i < *numSuccessors; i++) {
        successors[i].floor = loc->floor;
        // If the successor is the lift, adjust the floor number
        if (successors[i].room[0] == 'L' && successors[i].room[1] == 'I') {
            if (loc->floor < NUM_FLOORS && strcmp(successors[i].room, "LIFT1") != 0) {
                successors[i].floor++;
            } else if (loc->floor > 1 && strcmp(successors[i].room, "LIFT1") == 0) {
                successors[i].floor--;
            }
        }
    }
}

// Print the path
void printPath(Path *path) {
    for (int i = 0; i < path->pathLength; i++) {
        printf("%s ", path->path[i].room);
        if (i < path->pathLength - 1) {
            printf("-> ");
        }
    }
    printf("\n");
}

// The BFS algorithm to find the shortest path
void findShortestPath(Location start, Location end) {
    PathQueue queue;
    initializeQueue(&queue);
    
    Path startPath;
    startPath.pathLength = 1;
    startPath.path[0] = start;
    
    enqueue(&queue, &startPath);

    while (!isEmpty(&queue)) {
        Path currentPath;
        dequeue(&queue, &currentPath);
        Location currentLocation = currentPath.path[currentPath.pathLength - 1];

        if (isChargingRoom(&currentLocation)) {
            printPath(&currentPath);
            return;
        }

        Location successors[NUM_ROOMS_PER_FLOOR];
        int numSuccessors;
        getSuccessors(&currentLocation, successors, &numSuccessors);

        for (int i = 0; i < numSuccessors; i++) {
            Path newPath = currentPath;
            newPath.path[newPath.pathLength++] = successors[i];
            enqueue(&queue, &newPath);
        }
    }

    printf("No path found.\n");
}

int main() {
    Location startLocations[3] = {{"K3.2", 3}, {"LIFT1", 1}, {"K1.1", 1}};
    Location chargingRoom = {"CHARGE", 1};

    for (int i = 0; i < 3; i++) {
        printf("Scenario %d: Starting from %s\n", i + 1, startLocations[i].room);
        findShortestPath(startLocations[i], chargingRoom);
        printf("\n");
    }

    return 0;
}
