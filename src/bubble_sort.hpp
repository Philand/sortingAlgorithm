#pragma once

#include <cassert>
#include <iterator>

/**
 * @brief Sorts a range in ascending order using the bubble sort algorithm.
 *
 * Bubble sort repeatedly walks through the range, comparing each pair of
 * adjacent elements and swapping them if they are in the wrong order. On
 * every pass, the largest remaining element "bubbles up" towards the end
 * of the range, the same way a bubble rises to the surface of water.
 *
 * The algorithm stops as soon as a full pass makes no swap, since that
 * means the range is already sorted.
 *
 * @tparam It A random-access iterator type.
 * @param begin Iterator to the first element of the range.
 * @param end Iterator to one past the last element of the range.
 *
 * @note Best case O(n) (already sorted input), average and worst case
 *       O(n^2).
 */
template <std::random_access_iterator It>
void bubbleSort(It begin, It end)
{
    assert(begin <= end);

    if (begin == end)
    {
        return;
    }

    bool hasSwapped = true;
    while (hasSwapped)
    {
        hasSwapped = false;

        // One pass: compare every pair of neighbors up to the last element.
        for (It current = begin; current != end - 1; ++current)
        {
            It next = current + 1;
            if (*next < *current)
            {
                std::iter_swap(current, next);
                hasSwapped = true;
            }
        }
    }
}
