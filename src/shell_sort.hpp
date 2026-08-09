#pragma once

#include <cassert>
#include <iterator>

/**
 * @brief Sorts a range
 *
 * Shell sort ...
 *
 * @tparam It A random-access iterator type.
 * @param begin Iterator to the first element of the range.
 * @param end Iterator to one past the last element of the range.
 *
 * @note
 */
template <std::random_access_iterator It>
void shellSort(It begin, It end)
{
    assert(begin <= end);

    if (begin == end)
    {
        return;
    }

    std::vector<int> gaps = {701, 301, 132, 57, 23, 10, 4, 1};

    for ( auto g: gaps)
    {
        for (It current = begin + g; current < end; ++current)
        {
            for (It negIt = current; negIt - begin >= g; negIt -= g)
            {
                It prevIt = negIt - g;
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
}