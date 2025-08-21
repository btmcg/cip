#include "c05_sliding_windows.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("chapter 5", "[chapter_5]")
{
    SECTION("Substring Anagrams")
    {
        REQUIRE(substring_anagrams("", "") == 0);
        REQUIRE(substring_anagrams("abc", "abcd") == 0);

        REQUIRE(substring_anagrams("caabab", "aba") == 2);
    }
}
