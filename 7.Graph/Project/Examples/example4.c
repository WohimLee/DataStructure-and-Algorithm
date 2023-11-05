


#include "Utils.h"

int main(int argc, char** argv)
{
    char buffer[BUFFER_SIZE];
    FILE *file;
    CSVRow row;

    file = fopen("./workspace/adjacencyList.csv", "r");
    if (!file) {
        perror("Unable to open the file.");
        return EXIT_FAILURE;
    }

    while (fgets(buffer, BUFFER_SIZE, file)) {
        // Remove trailing newline
        buffer[strcspn(buffer, "\n\r")] = 0;
        
        processCSVRow(buffer, &row);

        // Do something with the CSV row here...
        printf("Index: %d\nRoom Type: %s\nDescription: %s\nConnections: ",
               row.idx, row.roomType, row.description);
        for (int i = 0; i < row.arcCount; i++) {
            printf("%d ", row.arcs[i]);
        }
        printf("\n\n");
    }
    fclose(file);
    return EXIT_SUCCESS;
}

