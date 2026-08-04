#pragma once

#include <algorithm>
#include <deque>
#include <vector>

#include <catch2/catch_test_macros.hpp>

// Common correctness checks shared by every sorting algorithm test suite.
// Each algorithm's tests calls this once with its own sort function,
// then only adds what's specific to that algorithm (e.g. stability).
template <typename SortFn>
void checkSortsCorrectly(SortFn sort)
{
    SECTION("sorts an unordered vector")
    {
        std::vector<int> values = {5, 3, 8, 1, 9, 2};
        sort(values.begin(), values.end());
        REQUIRE(std::is_sorted(values.begin(), values.end()));
    }

    SECTION("keeps an already sorted vector unchanged")
    {
        std::vector<int> values = {1, 2, 3, 4, 5};
        sort(values.begin(), values.end());
        REQUIRE(values == std::vector<int>{1, 2, 3, 4, 5});
    }

    SECTION("reverses a strictly descending vector")
    {
        std::vector<int> values = {5, 4, 3, 2, 1};
        sort(values.begin(), values.end());
        REQUIRE(values == std::vector<int>{1, 2, 3, 4, 5});
    }

    SECTION("handles an empty vector")
    {
        std::vector<int> values;
        sort(values.begin(), values.end());
        REQUIRE(values.empty());
    }

    SECTION("handles a single-element vector")
    {
        std::vector<int> values = {42};
        sort(values.begin(), values.end());
        REQUIRE(values == std::vector<int>{42});
    }

    SECTION("handles duplicate values")
    {
        std::vector<int> values = {3, 1, 3, 2, 1};
        sort(values.begin(), values.end());
        REQUIRE(values == std::vector<int>{1, 1, 2, 3, 3});
    }

    SECTION("works on any random-access container, not only std::vector")
    {
        std::deque<int> values = {5, 3, 8, 1, 9, 2};
        sort(values.begin(), values.end());
        REQUIRE(std::is_sorted(values.begin(), values.end()));
    }

    SECTION("sorts a std::vector<double>")
    {
        std::vector<double> values = {4.384, 19.332, 347.3, 3894.12, 90, 2088.47, 0.002,
                                      38.3, 0.003, 46.7, 39994.76, 36.2, 86.666, -1.3};
        sort(values.begin(), values.end());
        REQUIRE(std::is_sorted(values.begin(), values.end()));
    }
}
