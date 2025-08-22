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

    SECTION("Longest Substring With Unique Characters")
    {
        REQUIRE(longest_substring_with_unique_characters("") == 0);
        REQUIRE(longest_substring_with_unique_characters("abcba") == 3);
        REQUIRE(longest_substring_with_unique_characters("cabcdeca") == 5);

        REQUIRE(longest_substring_with_unique_characters_optimized("") == 0);
        REQUIRE(longest_substring_with_unique_characters_optimized("abcba") == 3);
        REQUIRE(longest_substring_with_unique_characters_optimized("cabcdeca") == 5);
    }

    SECTION("Longest Uniform Substring After Replacements")
    {
        REQUIRE(longest_uniform_substring_after_replacements("", 0) == 0);
        REQUIRE(longest_uniform_substring_after_replacements("aabcdcca", 2) == 5);
    }
}
