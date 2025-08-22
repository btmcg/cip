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

// Longest Substring With Unique Characters
// Give a string, determine the length of its longest substring that
// consists only of unique characters
int
longest_substring_with_unique_characters(std::string const& s)
{
    int max_len = 0;
    std::unordered_set<char> hash_set;
    int left = 0;
    int right = 0;

    while (static_cast<std::size_t>(right) < s.size()) {
        // if we encounter a duplicate character in the window, shrink
        // the window until it's no longer a duplicate
        while (hash_set.contains(s[right])) {
            hash_set.erase(s[left]);
            ++left;
        }

        // once there are no more duplicates in the window, update
        // 'max_len' if the corrent window is larger
        max_len = std::max(max_len, right - left + 1);
        hash_set.emplace(s[right]);

        // expand the window
        ++right;
    }
    return max_len;
}

int
longest_substring_with_unique_characters_optimized(std::string const& s)
{
    int max_len = 0;
    std::unordered_map<char, std::size_t> prev_indexes;
    int left = 0;
    int right = 0;

    while (static_cast<std::size_t>(right) < s.size()) {
        // if a previous index of the current character is present in
        // the current window, it's a duplicate character in the window
        if (prev_indexes.contains(s[right])
                && prev_indexes[s[right]] >= static_cast<std::size_t>(left)) {
            // shrink the window to exclude the previous occurrence of
            // this character
            left = prev_indexes[s[right]] + 1;
        }

        // update 'max_len' if the current window is larger
        max_len = std::max(max_len, right - left + 1);
        prev_indexes[s[right]] = right;

        // expand the window
        ++right;
    }

    return max_len;
}

