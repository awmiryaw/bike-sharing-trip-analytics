#include <assert.h>
#include <stdio.h>
#include "trip.h"
#include "analytics.h"

int main(void) {
    Trip trips[] = {
        {"T001", "05/01/2026", 10},
        {"T002", "12/01/2026", 30},
        {"T003", "03/02/2026", 20},
        {"T004", "20/02/2026", 15}
    };

    int counts[MONTHS];
    Trip *longest[MONTHS];
    Trip *shortest[MONTHS];

    countTripsByMonth(trips, 4, counts);
    longestTripByMonth(trips, 4, longest);
    shortestTripByMonth(trips, 4, shortest);

    assert(counts[0] == 2);
    assert(counts[1] == 2);
    assert(longest[0]->duration == 30);
    assert(shortest[0]->duration == 10);
    assert(totalDuration(trips, 4) == 75);
    assert(busiestMonth(counts) == 0);

    printf("All tests passed.\n");
    return 0;
}
