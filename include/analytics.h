#ifndef ANALYTICS_H
#define ANALYTICS_H

#include "trip.h"

void countTripsByMonth(Trip trips[], int nTrips, int counts[]);
void longestTripByMonth(Trip trips[], int nTrips, Trip *longest[]);
void shortestTripByMonth(Trip trips[], int nTrips, Trip *shortest[]);
int totalDuration(Trip trips[], int nTrips);
double averageDuration(Trip trips[], int nTrips);
int busiestMonth(int counts[]);

#endif
