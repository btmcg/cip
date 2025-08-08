#include "chapter_1.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("chapter 1", "[chapter_1]")
{
    SECTION("Pair Sum - Sorted")
    {
        REQUIRE(pair_sum_sorted({-5, -2, 3, 4, 6}, 7) == std::vector{2, 3});
        REQUIRE(pair_sum_sorted({1, 1, 1}, 2) == std::vector{0, 2});

        REQUIRE(pair_sum_sorted({}, 0) == std::vector<int>{});
        REQUIRE(pair_sum_sorted({1}, 1) == std::vector<int>{});
        REQUIRE(pair_sum_sorted({2, 3}, 5) == std::vector{0, 1});
        REQUIRE(pair_sum_sorted({2, 4}, 5) == std::vector<int>{});
        REQUIRE(pair_sum_sorted({2, 2, 3}, 5) == std::vector{0, 2});
        REQUIRE(pair_sum_sorted({-1, 2, 3}, 2) == std::vector{0, 2});
        REQUIRE(pair_sum_sorted({-3, -2, -1}, -5) == std::vector{0, 1});
    }

    SECTION("Triplet Sum")
    {
        auto triplets = triplet_sum({0, -1, 2, -3, 1});
        REQUIRE(triplets[0].a == -3);
        REQUIRE(triplets[0].b == 1);
        REQUIRE(triplets[0].c == 2);
        REQUIRE(triplets[1].a == -1);
        REQUIRE(triplets[1].b == 0);
        REQUIRE(triplets[1].c == 1);

        REQUIRE(triplet_sum({0, -1, 2, -3, 1}) == std::vector<triplet>{{-3, 1, 2}, {-1, 0, 1}});

        REQUIRE(triplet_sum({}).empty());
    }
}
