#pragma once

#include <cassert>
#include <iterator>

/**
 * @brief Sorts a range
 *
 * Insertion sort ...
 *
 * @tparam It A random-access iterator type.
 * @param begin Iterator to the first element of the range.
 * @param end Iterator to one past the last element of the range.
 *
 * @note
 */
template <std::random_access_iterator It>
void insertionSort(It begin, It end)
{
    assert(begin <= end);

    if (begin == end)
    {
        return;
    }

    for (It current = begin + 1; current != end; ++current)
    {
        for (It negIt = current; negIt != begin; --negIt)
        {
            It prevIt = negIt - 1;
            if (*negIt < *prevIt)
            {
                std::iter_swap(negIt, prevIt);
            }
            else
            {
                break;
            }
        }
    }
}