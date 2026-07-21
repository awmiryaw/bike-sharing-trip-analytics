#include <stdio.h>
#include <string.h>
#include "file_reader.h"

int readTrips(char *filename, Trip trips[], int maxSize) {
    FILE *fp;
    char line[200];
    int n = 0;
    int lineNumber = 0;

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    while (n < maxSize && fgets(line, sizeof(line), fp) != NULL) {
        Trip temp;
        int read;

        lineNumber++;

        if (lineNumber == 1 && strstr(line, "trip_id") != NULL)
            continue;

        read = sscanf(line, "%9[^,],%10[^,],%d",
                      temp.tripID,
                      temp.date,
                      &temp.duration);

        if (read == 3 && validTrip(&temp)) {
            trips[n] = temp;
            n++;
        } else {
            printf("Invalid row skipped: %d\n", lineNumber);
        }
    }

    fclose(fp);
    return n;
}
