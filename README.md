# sortingAlgorithm

SortingAlgorithm is a personnal project implementing sorting algorithms in C++20, following the list on the Wikipedia page [Sorting algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm).

Each algorithm is generic (templated on `std::random_access_iterator`), header-only, and tested by [Catch2](https://github.com/catchorg/Catch2) unit tests.

Each sorting algorithm operates on a **pair of iterators** (`begin`, `end`) rather than on a concrete container like the usual `std::vector<int>`, the same way the C++ standard library does it with `std::sort`. For more information, see the [design documentation]().

## Implemented algorithms
- [Bubble sort](doc/sorting_algorithm.md#bubble-sort)
- [Selection sort](doc/sorting_algorithm.md#selection-sort)

## Build
```bash
mkdir -p build && cd build
cmake ..
cmake --build .
```

## Run tests
```bash
cd build
ctest
```