include(FetchContent)

FetchContent_Declare(
    catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.7.1
)
FetchContent_MakeAvailable(catch2)

add_executable(sortingAlgorithm_tests sorting_algorithm_test.cpp)
target_link_libraries(sortingAlgorithm_tests PRIVATE sortingAlgorithm Catch2::Catch2WithMain)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)
catch_discover_tests(sortingAlgorithm_tests)