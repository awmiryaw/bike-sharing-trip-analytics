#include <stdio.h>
#include <stdlib.h>
#include "trip.h"
#include "file_reader.h"
#include "analytics.h"

#define MAX_TRIPS 1000

int main(int argc, char *argv[]) {
    Trip trips[MAX_TRIPS];
    Trip *longest[MONTHS] = {NULL};
    Trip *shortest[MONTHS] = {NULL};
    int counts[MONTHS] = {0};
    int nTrips;
    int busy;
    int i;

    char *months[] = {
        "January", "February", "March",
        "April", "May", "June"
    };

    if (argc != 2) {
        printf("Correct usage: %s <file.csv>\n", argv[0]);
        return 1;
    }

    nTrips = readTrips(argv[1], trips, MAX_TRIPS);

    if (nTrips < 0)
        return 1;

    if (nTrips == 0) {
        printf("No valid trips found.\n");
        return 0;
    }

    countTripsByMonth(trips, nTrips, counts);
    longestTripByMonth(trips, nTrips, longest);
    shortestTripByMonth(trips, nTrips, shortest);
    busy = busiestMonth(counts);

    printf("BIKE SHARING TRIP REPORT\n\n");
    printf("Trips loaded: %d\n", nTrips);
    printf("Total duration: %d minutes\n", totalDuration(trips, nTrips));
    printf("Average duration: %.2f minutes\n", averageDuration(trips, nTrips));

    if (busy != -1)
        printf("Busiest month: %s\n", months[busy]);

    printf("\nTrips by month:\n");

    for (i = 0; i < MONTHS; i++) {
        printf("\n%s: %d trips\n", months[i], counts[i]);

        if (longest[i] != NULL) {
            printf("Longest trip: %s, %d minutes\n",
                   longest[i]->tripID,
                   longest[i]->duration);

            printf("Shortest trip: %s, %d minutes\n",
                   shortest[i]->tripID,
                   shortest[i]->duration);
        } else {
            printf("No trips.\n");
        }
    }

    return 0;
}
