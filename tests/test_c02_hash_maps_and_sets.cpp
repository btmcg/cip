#include "c02_hash_maps_and_sets.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("chapter 2", "[chapter_2]")
{
    SECTION("Pair Sum - Unsorted")
    {
        auto result = pair_sum_unsorted({-1, 3, 4, 2}, 3);
        REQUIRE(result.size() == 1);
        REQUIRE(result[0] == std::pair{0, 2});
    }

    SECTION("Verify Sudoku Board")
    {
        // clang-format off
        REQUIRE_FALSE(verify_sudoku_board(std::vector<std::vector<int>>{
            { 3, 0, 6,  0, 5, 8,    4, 0, 0 },
            { 5, 2, 0,  0, 0, 0,    0, 0, 0 },
            { 0, 8, 7,  0, 0, 0,    0, 3, 1 },

            { 1, 0, 2,  5, 0, 0,    3, 2, 0 }, // two 2's
            { 9, 0, 0,  8, 6, 3,    0, 0, 5 },
            { 0, 5, 0,  0, 9, 0,    6, 0, 0 },

            { 0, 3, 0,  0, 0, 8,    2, 5, 0 },
            { 0, 1, 0,  0, 0, 0,    0, 7, 4 },
            { 0, 0, 5,  2, 0, 6,    0, 0, 0 }}));
                              // two 8's
        REQUIRE(verify_sudoku_board(std::vector<std::vector<int>>{
            { 3, 0, 6,  0, 5, 0,    4, 0, 0 },
            { 5, 2, 0,  0, 0, 0,    0, 0, 0 },
            { 0, 8, 7,  0, 0, 0,    0, 3, 1 },

            { 1, 0, 2,  5, 0, 0,    3, 0, 0 },
            { 9, 0, 0,  8, 6, 3,    0, 0, 5 },
            { 0, 5, 0,  0, 9, 0,    6, 0, 0 },

            { 0, 3, 0,  0, 0, 8,    2, 5, 0 },
            { 0, 1, 0,  0, 0, 0,    0, 7, 4 },
            { 0, 0, 5,  2, 0, 6,    0, 0, 0 }}));
        REQUIRE_FALSE(verify_sudoku_board(std::vector<std::vector<int>>{
            { 3, 0, 6,  0, 5, 0,    4, 0, 0 },
            { 5, 2, 0,  0, 0, 0,    0, 0, 3 }, // subgrid has two 3's
            { 0, 8, 7,  0, 0, 0,    0, 3, 1 },

            { 1, 0, 2,  5, 0, 0,    3, 0, 0 },
            { 9, 0, 0,  8, 6, 3,    0, 0, 5 },
            { 0, 5, 0,  0, 9, 0,    6, 0, 0 },

            { 0, 3, 0,  0, 0, 8,    2, 5, 0 },
            { 0, 1, 0,  0, 0, 0,    0, 7, 4 },
            { 0, 0, 5,  2, 0, 6,    0, 0, 0 }}));

        // clang-format on
    }
}
