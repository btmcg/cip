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
}
