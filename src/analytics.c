#include <stddef.h>
#include "analytics.h"

void countTripsByMonth(Trip trips[], int nTrips, int counts[]) {
    int i;
    int month;

    for (i = 0; i < MONTHS; i++)
        counts[i] = 0;

    for (i = 0; i < nTrips; i++) {
        month = getMonth(&trips[i]);

        if (month >= 1 && month <= MONTHS)
            counts[month - 1]++;
    }
}

void longestTripByMonth(Trip trips[], int nTrips, Trip *longest[]) {
    int i;
    int month;
    int pos;

    for (i = 0; i < MONTHS; i++)
        longest[i] = NULL;

    for (i = 0; i < nTrips; i++) {
        month = getMonth(&trips[i]);
        pos = month - 1;

        if (pos >= 0 && pos < MONTHS) {
            if (longest[pos] == NULL ||
                trips[i].duration > longest[pos]->duration) {
                longest[pos] = &trips[i];
            }
        }
    }
}

void shortestTripByMonth(Trip trips[], int nTrips, Trip *shortest[]) {
    int i;
    int month;
    int pos;

    for (i = 0; i < MONTHS; i++)
        shortest[i] = NULL;

    for (i = 0; i < nTrips; i++) {
        month = getMonth(&trips[i]);
        pos = month - 1;

        if (pos >= 0 && pos < MONTHS) {
            if (shortest[pos] == NULL ||
                trips[i].duration < shortest[pos]->duration) {
                shortest[pos] = &trips[i];
            }
        }
    }
}

int totalDuration(Trip trips[], int nTrips) {
    int i;
    int total = 0;

    for (i = 0; i < nTrips; i++)
        total += trips[i].duration;

    return total;
}

double averageDuration(Trip trips[], int nTrips) {
    if (nTrips == 0)
        return 0;

    return (double) totalDuration(trips, nTrips) / nTrips;
}

int busiestMonth(int counts[]) {
    int i;
    int pos = -1;
    int max = 0;

    for (i = 0; i < MONTHS; i++) {
        if (counts[i] > max) {
            max = counts[i];
            pos = i;
        }
    }

    return pos;
}
