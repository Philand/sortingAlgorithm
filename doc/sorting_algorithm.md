# Sorting algorithms documentation

Short documentation for each sorting algorithm implemented: principle,
complexity, and links to its implementation and tests. See
[Sorting algorithm — Wikipedia](https://en.wikipedia.org/wiki/Sorting_algorithm)
for the full list this project draws from.

The French Wikipedia pages on various algorithms feature a nice animation that illustrates how each sorting algorithm works.

The code's design is explained in the [Design](#design) section at the end of the file.

## Summary

| Algorithm | Best | Average | Worst | Memory | Stable |
|---|---|---|---|---|---|
| [Bubble sort](#bubble-sort) | O(n) | O(n²) | O(n²) | O(1) | Yes |
| [Selection sort](#selection-sort) | O(n²) | O(n²) | O(n²) | O(1) | No |

## Bubble sort

Source: [Bubble sort — Wikipedia](https://en.wikipedia.org/wiki/Bubble_sort)

**Principle** — Bubble sort repeatedly walks through the range, comparing each
pair of adjacent elements and swapping them if they are in the wrong order. On
every pass, the largest remaining element "bubbles up" towards the end of the
range, the same way a bubble rises to the surface of water. The pass repeats
until a full pass makes no swap, which means the range is already sorted.

**Complexity** — best case O(n) when the input is already sorted (early exit
via the swap-tracking flag), average and worst case O(n²), O(1) extra memory.
Bubble sort is **stable**: it never swaps two equal elements, so their
relative order is preserved.

**Implementation**
- [`src/bubble_sort.hpp`](../src/bubble_sort.hpp) — generic implementation
  working on any `std::random_access_iterator` range.
- Tests: `BubbleSortFn` in
  [`test/sorting_algorithms_test.cpp`](../test/sorting_algorithms_test.cpp).

## Selection sort

Source: [Selection sort — Wikipedia](https://en.wikipedia.org/wiki/Selection_sort)

**Principle** — Selection sort repeatedly scans the remaining unsorted
portion of the range to find its smallest element, then swaps that element
into place at the front of that portion. Once a position holds its final
value, the algorithm never revisits it, and moves on to select the next
position the same way.

**Complexity** — always O(n²) time, since both loops run their full course
regardless of how sorted the input already is (unlike bubble sort, there is
no early exit). O(1) extra memory. Selection sort is **not stable**: swapping
the found minimum into place can reorder equal elements.

**Implementation**
- [`src/selection_sort.hpp`](../src/selection_sort.hpp) — generic
  implementation working on any `std::random_access_iterator` range.
- Tests: `SelectionSortFn` in
  [`test/sorting_algorithms_test.cpp`](../test/sorting_algorithms_test.cpp).

## Design

### Using iterators instead of raw values or a single container type

An iterator represents a **position** in a range, decoupled from both the container
that holds the data and the type of the values themselves. The algorithm only needs
two operations on that position: move to the next one (`++it`) and read/write the
value it points to (`*it`). It never needs to know *how* the data is stored.

That decoupling buys two things:

- **One implementation, many containers and types.** The same sorting algorithm works
  unmodified on a `std::vector<int>`, a `std::deque<double>`, a plain C array, or a
  container of custom structs, as long as it exposes random-access iterators. Writing
  the algorithm against a concrete container (e.g.
  `void bubbleSort(std::vector<int>&)`) would require a near-identical copy for every
  container/type combination we'd want to sort.
- **No runtime cost for that flexibility.** Because `It` is a template parameter, the
  compiler generates a fully specialized version of the function for each concrete
  iterator type actually used, at compile time. There is no virtual dispatch, no type
  erasure, no boxing: the generated machine code is exactly what hand-writing the
  algorithm for that one specific type would produce. This is C++'s "zero-cost
  abstraction" principle — genericity here costs nothing at runtime, only a bit of
  compile time.

### Using header-only for each sorting algorithm.

Because each algorithm is a template, the compiler must see its full body at every
call site to generate the specialized version for the iterator type used there — it
can't compile the body once into a `.cpp` file and link against it like an ordinary
function, since there would be nothing concrete to generate code from. So the
implementation has to live in the header that gets `#include`d wherever the algorithm
is used.