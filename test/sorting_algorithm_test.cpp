#include <catch2/catch_template_test_macros.hpp>
#include <catch2/catch_test_macros.hpp>

#include "bubble_sort.hpp"
#include "selection_sort.hpp"
#include "sort_test_helpers.hpp"

struct BubbleSortFn
{
    template <typename It>
    void operator()(It begin, It end) const
    {
        bubbleSort(begin, end);
    }
};

struct SelectionSortFn
{
    template <typename It>
    void operator()(It begin, It end) const
    {
        selectionSort(begin, end);
    }
};

// One entry per implemented sorting algorithm: adding a new algorithm to the
// project only requires a new functor above and one more type in this list.
TEMPLATE_TEST_CASE("Sorting algorithm", "[sort]",
    BubbleSortFn,
    SelectionSortFn
)
{
    checkSortsCorrectly(TestType{});
}
