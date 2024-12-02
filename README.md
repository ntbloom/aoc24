# aoc24

[Advent of Code 2024](https://adventofcode.com/2024/) in C++.

### How to start a new day

Add a new day using the `addDay.sh` script. Specify the number/name of the day as well as what type you want the puzzle
to return.

```shell
# format is ./addDay.sh  -i <integer> -s <string> -t <data type> 
./addDay -i 1 -s one -t size_t
./addDay -i 2 -s two string
```

Uncomment the headers and day in the switch statement in `main.cpp` and you should have a stubbed out `<number>.cpp`
file in the `src/` directory and `<number>.hpp` file in the `include/` directory.

Write unit tests in `test/unit_tests.cpp` if needed, or keep track of answers in `test/test_solutions.cpp` after you've
successfully solved a puzzle.

### How to run

Build with `make all` (first time) or just `make`. Print your solution using the `make answer` target:

```shell
make answer day=14 # runs both parts
make answer day=14 puzzle=2 # just specify a single puzzle
```