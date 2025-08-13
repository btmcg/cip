#include "c01_two_pointers.hpp"
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
        REQUIRE(triplet_sum({0, -1, 2, -3, 1}) == std::vector<triplet>{{-3, 1, 2}, {-1, 0, 1}});

        REQUIRE(triplet_sum({}).empty());
        REQUIRE(triplet_sum({0}).empty());
        REQUIRE(triplet_sum({1, -1}).empty());
        REQUIRE(triplet_sum({0, 0, 0}) == std::vector<triplet>{{0, 0, 0}});
        REQUIRE(triplet_sum({1, 0, 1}).empty());
        REQUIRE(triplet_sum({0, 0, 1, -1, 1, -1}) == std::vector<triplet>{{-1, 0, 1}});
    }

    SECTION("Is Palindrome Valid")
    {
        REQUIRE(is_palindrome_valid("a dog! a panic  in a pagoda."));
        REQUIRE_FALSE(is_palindrome_valid("abc123"));
        REQUIRE(is_palindrome_valid(""));
        REQUIRE(is_palindrome_valid("a"));
        REQUIRE(is_palindrome_valid("aa"));
        REQUIRE_FALSE(is_palindrome_valid("ab"));
        REQUIRE(is_palindrome_valid("!, (?)"));
        REQUIRE(is_palindrome_valid("12.02.2021"));
        REQUIRE_FALSE(is_palindrome_valid("21.02.2021"));
        REQUIRE_FALSE(is_palindrome_valid("hello, world!"));
    }

    SECTION("Largest Container")
    {
        REQUIRE(largest_container({2, 7, 8, 3, 7, 6}) == 24);
        REQUIRE(largest_container({}) == 0);
        REQUIRE(largest_container({1}) == 0);
        REQUIRE(largest_container({0, 1, 0}) == 0);
        REQUIRE(largest_container({3, 3, 3, 3}) == 9);
        REQUIRE(largest_container({1, 2, 3}) == 2);
        REQUIRE(largest_container({3, 2, 1}) == 2);
    }

    SECTION("Shift Zeroes to the End")
    {
        {
            std::vector<int> arr{0, 1, 0, 3, 2};
            shift_zeroes_to_the_end(arr);
            REQUIRE(arr == std::vector{1, 3, 2, 0, 0});
        }

        {
            std::vector<int> arr;
            shift_zeroes_to_the_end(arr);
            REQUIRE(arr == std::vector<int>{});
        }

        {
            std::vector<int> arr{0};
            shift_zeroes_to_the_end(arr);
            REQUIRE(arr == std::vector{0});
        }

        {
            std::vector<int> arr{1};
            shift_zeroes_to_the_end(arr);
            REQUIRE(arr == std::vector{1});
        }

        {
            std::vector<int> arr{0, 0, 0};
            shift_zeroes_to_the_end(arr);
            REQUIRE(arr == std::vector{0, 0, 0});
        }

        {
            std::vector<int> arr{1, 3, 2};
            shift_zeroes_to_the_end(arr);
            REQUIRE(arr == std::vector{1, 3, 2});
        }

        {
            std::vector<int> arr{1, 1, 1, 0, 0};
            shift_zeroes_to_the_end(arr);
            REQUIRE(arr == std::vector{1, 1, 1, 0, 0});
        }

        {
            std::vector<int> arr{0, 0, 1, 1, 1};
            shift_zeroes_to_the_end(arr);
            REQUIRE(arr == std::vector{1, 1, 1, 0, 0});
        }
    }

    SECTION("Next Lexicographical Sequence")
    {
        REQUIRE(next_lexicographical_sequence("abcd") == "abdc");
        REQUIRE(next_lexicographical_sequence("dcba") == "abcd");
        REQUIRE(next_lexicographical_sequence("a") == "a");
        REQUIRE(next_lexicographical_sequence("aaaa") == "aaaa");
        REQUIRE(next_lexicographical_sequence("ynitsed") == "ynsdeit");
    }
}
