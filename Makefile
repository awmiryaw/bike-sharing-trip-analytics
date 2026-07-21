CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Iinclude

PROGRAM = bike_analytics
TEST = test_analytics

SOURCES = src/main.c src/trip.c src/file_reader.c src/analytics.c
TEST_SOURCES = tests/test_analytics.c src/trip.c src/analytics.c

all:
	$(CC) $(CFLAGS) $(SOURCES) -o $(PROGRAM)

run: all
	./$(PROGRAM) data/sample_trips.csv

test:
	$(CC) $(CFLAGS) $(TEST_SOURCES) -o $(TEST)
	./$(TEST)

clean:
	rm -f $(PROGRAM) $(TEST)
