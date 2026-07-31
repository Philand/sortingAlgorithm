#pragma once

#include <cassert>
#include <iterator>

/**
 * @brief Sorts a range in ascending order using the selection sort algorithm.
 *
 * Selection sort repeatedly scans the remaining unsorted portion of the
 * range to find its smallest element, then swaps that element into place
 * at the front of that portion. Once a position holds its final value, the
 * algorithm never revisits it, and moves on to select the next position the
 * same way.
 *
 * @tparam It A random-access iterator type.
 * @param begin Iterator to the first element of the range.
 * @param end Iterator to one past the last element of the range.
 *
 * @note Always O(n^2) time, since both loops run their full course
 *       regardless of how sorted the input already is (unlike bubble sort,
 *       there is no early exit).
 */
template <std::random_access_iterator It>
void selectionSort(It begin, It end)
{
    assert(begin <= end);

    if (begin == end)
    {
        return;
    }

    for (It current = begin; current != end - 1; ++current)
    {
        It minIt = current;
        for (It next = current + 1; next != end; ++next)
        {
            if (*next < *minIt)
            {
                minIt = next;
            }
        }
        std::iter_swap(current, minIt);
    }
}