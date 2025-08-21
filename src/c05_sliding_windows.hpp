#include <algorithm> // std::sort
#include <array>
#include <cctype> // std::isalnum
#include <cmath>  // std::floor, std::pow
#include <print>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility> // std::pair
#include <vector>

// Substring Anagrams
// Given two strings, s and t, both consisting of lowercase English
// letters, return the number of substrings in s that are anagrams of t.
// An anagram is a word or phrase formed by rearranging the letters of
// another word or phrase, using all the original letters exactly once.
int
substring_anagrams(std::string const& s, std::string const& t)
{
    std::size_t len_s = s.size();
    std::size_t len_t = t.size();

    if (len_t > len_s) {
        return 0;
    }

    int count = 0;
    std::array<int, 26> expected_freqs = {0};
    std::array<int, 26> window_freqs = {0};

    // populate 'expected_freqs' with the characters in string 't'.
    for (char c : t) {
        expected_freqs[c - 'a'] += 1;
    }

    std::size_t left = 0;
    std::size_t right = 0;

    while (right < len_s) {
        // add the character at the right pointer to 'window_freqs'
        // before sliding the window
        window_freqs[s[right] - 'a'] += 1;

        // if the window has reached the expected fixed length, we
        // advance the left pointer as well as the right pointer to
        // slide the window
        if (right - left + 1 == len_t) {
            if (window_freqs == expected_freqs) {
                ++count;
            }

            // remove the character at the left pointer from
            // 'window_freqs' before advancing the left pointer
            window_freqs[s[left] - 'a'] -= 1;
            ++left;
        }
        ++right;
    }
    return count;
}
