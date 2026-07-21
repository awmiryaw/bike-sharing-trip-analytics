# Bike-Sharing Trip Analytics

A C command-line program that reads bike-sharing trips from a CSV file and produces a monthly report.

The project demonstrates file handling, structures, arrays, pointers, validation, and modular programming in C.

## Features

- Reads trip data from a CSV file
- Checks and skips invalid records
- Counts trips for each month from January to June
- Finds the longest trip of each month
- Finds the shortest trip of each month
- Calculates total and average trip duration
- Finds the busiest month
- Includes a small automated test

## Technologies

- C
- Standard C library
- GCC
- Make

## Project Structure

```text
bike-sharing-trip-analytics/
├── data/
│ └── sample_trips.csv
├── include/
│ ├── analytics.h
│ ├── file_reader.h
│ └── trip.h
├── src/
│ ├── analytics.c
│ ├── file_reader.c
│ ├── main.c
│ └── trip.c
├── tests/
│ └── test_analytics.c
├── .gitignore
├── Makefile
└── README.md
```

## CSV Format

```csv
trip_id,date,duration
TRIP001,05/01/2026,18
TRIP002,12/01/2026,42
```

The date format is `dd/mm/yyyy` and duration is expressed in minutes.

## Compile

```bash
make
```

## Run

```bash
make run
```

or:

```bash
./bike_analytics data/sample_trips.csv
```

## Test

```bash
make test
```

Expected output:

```text
All tests passed.
```

## Main Logic

The project is divided into separate files:

- `file_reader.c` reads and validates the CSV data.
- `trip.c` checks trip records and extracts the month.
- `analytics.c` calculates monthly and general statistics.
- `main.c` calls the functions and prints the final report.

The longest and shortest trips are stored using pointers to the original trip array
