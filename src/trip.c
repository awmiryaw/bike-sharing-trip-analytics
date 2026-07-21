#include <string.h>
#include "trip.h"

int getMonth(Trip *trip) {
    int month;

    if (trip == NULL || strlen(trip->date) != 10)
        return -1;

    if (trip->date[2] != '/' || trip->date[5] != '/')
        return -1;

    if (trip->date[3] < '0' || trip->date[3] > '9' ||
        trip->date[4] < '0' || trip->date[4] > '9')
        return -1;

    month = (trip->date[3] - '0') * 10 + (trip->date[4] - '0');

    if (month < 1 || month > 12)
        return -1;

    return month;
}

int validTrip(Trip *trip) {
    if (trip == NULL)
        return 0;

    if (strlen(trip->tripID) == 0 || strlen(trip->tripID) >= MAX_ID)
        return 0;

    if (getMonth(trip) == -1)
        return 0;

    if (trip->duration <= 0)
        return 0;

    return 1;
}
