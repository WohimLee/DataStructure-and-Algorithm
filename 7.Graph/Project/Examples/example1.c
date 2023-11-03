#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    char room[10];
    struct Node* next;
} Node;

typedef struct QueueItem {
    char path[100];
    struct QueueItem* next;
} QueueItem;

typedef struct {
    QueueItem* front;
    QueueItem* rear;
} Queue;

void enqueue(Queue* q, const char* path) {
    QueueItem* temp = (QueueItem*)malloc(sizeof(QueueItem));
    strcpy(temp->path, path);
    temp->next = NULL;

    if (!q->front && !q->rear) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

char* dequeue(Queue* q) {
    if (!q->front) return NULL;

    QueueItem* temp = q->front;
    char* path = (char*)malloc(100);
    strcpy(path, temp->path);

    q->front = q->front->next;
    if (!q->front) q->rear = NULL;
    
    free(temp);
    return path;
}

bool isEmpty(Queue* q) {
    return q->front == NULL;
}

void successors(const char* room, Node** next_rooms) {
    // ... Fill the logic based on the room layout described previously
    // This will involve creating linked lists for each room's possible next rooms
    // For simplicity, we are skipping it here, but it would involve 
    // adding nodes to the next_rooms list based on the current room.
}

char* BFS(const char* initial_state, const char* goal_state) {
    Queue q = { .front = NULL, .rear = NULL };
    enqueue(&q, initial_state);

    while (!isEmpty(&q)) {
        char* current_path = dequeue(&q);
        char* current_room = strtok(current_path, " "); // Assume space-separated rooms in path
        while (strtok(NULL, " ")) {
            current_room = strtok(NULL, " ");
        }

        if (strcmp(current_room, goal_state) == 0) {
            return current_path;
        }

        Node* next_rooms = NULL;
        successors(current_room, &next_rooms);
        
        while (next_rooms) {
            char new_path[100];
            strcpy(new_path, current_path);
            strcat(new_path, " ");
            strcat(new_path, next_rooms->room);
            enqueue(&q, new_path);

            Node* temp = next_rooms;
            next_rooms = next_rooms->next;
            free(temp);
        }
        free(current_path);
    }
    return "No path found";
}

int main() {
    char* path1 = BFS("N3.2", "Charger");
    printf("Path from N3.2: %s\n", path1);
    free(path1);

    char* path2 = BFS("Lift1", "Charger");
    printf("Path from Lift1: %s\n", path2);
    free(path2);

    char* path3 = BFS("K1.1", "Charger");
    printf("Path from K1.1: %s\n", path3);
    free(path3);

    return 0;
}
