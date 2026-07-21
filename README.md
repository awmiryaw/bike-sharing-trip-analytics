# Bike-Sharing Trip Analytics

A C command-line program that reads bike-sharing trips from a CSV file and produces a monthly report.

The program was built to practice file handling, structures, arrays, pointers and modular programming in C.

## Features

- Reads trip data from a CSV file
- Checks invalid records
- Counts trips for each month from January to June
- Finds the longest trip of each month
- Finds the shortest trip of each month
- Calculates total and average trip duration
- Finds the busiest month
- Includes a small test file

## Technologies

- C
- Standard C library
- GCC
- Make

## Project Structure

```text
bike-sharing-trip-analytics/
├── data/
│   └── sample_trips.csv
├── include/
│   ├── analytics.h
│   ├── file_reader.h
│   └── trip.h
├── src/
│   ├── analytics.c
│   ├── file_reader.c
│   ├── main.c
│   └── trip.c
├── tests/
│   └── test_analytics.c
├── Makefile
└── README.md
```

## CSV Format

```csv
trip_id,date,duration
TRIP001,05/01/2026,18
TRIP002,12/01/2026,42
```

The date format is `dd/mm/yyyy` and duration is in minutes.

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

- `file_reader.c` reads the CSV file.
- `trip.c` checks trip data and extracts the month.
- `analytics.c` calculates the monthly statistics.
- `main.c` calls the functions and prints the report.

The longest and shortest trips are stored using pointers to the original trip array.
