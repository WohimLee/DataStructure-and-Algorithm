
#include "Test.h"

// Main function
int main() {
    bool visited[100] = {false};
    for(int i=0; i<5; i++)
        printf("%d\n", visited[i]);
    // Graph* graph = createGraph(4);
    // addEdge(graph, 0, 1);
    // addEdge(graph, 0, 2);
    // addEdge(graph, 1, 2);
    // addEdge(graph, 2, 3);

    // printf("Breadth First Search starting from vertex 2:\n");
    // BFS(graph, 2);

    // // Cleanup
    // for (int i = 0; i < graph->numVertices; i++) {
    //     free(graph->adjLists[i]);
    // }
    // free(graph->adjLists);
    // free(graph->visited);
    // free(graph);

    return 0;
}
