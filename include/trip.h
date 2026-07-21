#ifndef TRIP_H
#define TRIP_H

#define MONTHS 6
#define MAX_ID 10
#define DATE_SIZE 11

typedef struct {
    char tripID[MAX_ID];
    char date[DATE_SIZE];
    int duration;
} Trip;

int getMonth(Trip *trip);
int validTrip(Trip *trip);

#endif
