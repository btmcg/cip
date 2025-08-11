#include <algorithm> // std::sort
#include <cctype>    // std::isalnum
#include <print>
#include <string>
#include <tuple>
#include <utility> // std::pair
#include <vector>


// Pair Sum - Sorted
// Given an array of integers stored in ascending order and a target
// value, return the indexes of any pair of numbers in the array that
// sum to the target. The order of the indexes in the result doesn't
// matter. In no pair is found, return an empty array
std::vector<int>
pair_sum_sorted(std::vector<int> const& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int sum = nums[left] + nums[right];
        // if the sum is smaller, increment the left pointer, aiming to
        // increase the sum toward the target value
        if (sum < target) {
            ++left;
        }
        // if the sum is larger, decrement the right pointer, aiming to
        // decrease the sum toward the target value
        else if (sum > target) {
            --right;
        }
        // if the target pair is found, return its indexes
        else {
            return {left, right};
        }
    }
    return {};
}

// Given an array of integers, return all triplets [a, b, c] such that
// a + b + c = 0. The solution must not contain duplicate triplets
// (e.g., [1, 2, 3] and [2, 3, 1] are considered duplicate triplets). If
// no such triplets are found, return an empty array.
std::vector<std::pair<int, int>> pair_sum_sorted_all_pairs(
        std::vector<int> const& nums, int start, int target);
using triplet = std::tuple<int, int, int>;
std::vector<triplet>
triplet_sum(std::vector<int> const& nums)
{
    std::vector<triplet> triplets;
    auto sorted_nums = nums;
    std::sort(sorted_nums.begin(), sorted_nums.end());

    for (int i = 0; i < static_cast<int>(sorted_nums.size()); ++i) {
        // optimization: triplets consisting of only positive numbers
        // will never sum to 0
        if (sorted_nums[i] > 0) {
            break;
        }
        // to avoid duplicate triplets, skip 'a' if it's the same as the
        // previous number
        if (i > 0 && sorted_nums[i] == sorted_nums[i - 1]) {
            continue;
        }
        // find all pairs that sum to a target of '-a' (-sorted_nums[i])
        auto pairs = pair_sum_sorted_all_pairs(sorted_nums, i + 1, -sorted_nums[i]);
        for (auto& pair : pairs) {
            triplets.push_back({sorted_nums[i], pair.first, pair.second});
        }
    }
    return triplets;
}

std::vector<std::pair<int, int>>
pair_sum_sorted_all_pairs(std::vector<int> const& nums, int start, int target)
{
    std::vector<std::pair<int, int>> pairs;
    int left = start;
    int right = nums.size() - 1;

    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
            pairs.push_back({nums[left], nums[right]});
            ++left;
            // to avoid duplicate '[b, c]' pairs, skip 'b' if it's the
            // same as the previous number
            while (left < right && nums[left] == nums[left - 1]) {
                ++left;
            }
        } else if (sum < target) {
            ++left;
        } else {
            --right;
        }
    }

    return pairs;
}

// Given a string, determine if it's a palindrome after removing all
// non-alphanumeric characters. A character is alphanumeric if it's
// either a letter or a number.
bool
is_palindrome_valid(std::string const& s)
{
    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
        // skip non-alphanumeric characters from the left
        while (left < right && !std::isalnum(s[left])) {
            ++left;
        }
        // skip non-alphanumeric characters from the left
        while (left < right && !std::isalnum(s[right])) {
            --right;
        }
        // if the characters at the left and right pointers don't match,
        // the string is not a palindrome
        if (s[left] != s[right]) {
            return false;
        }
        ++left;
        --right;
    }

    return true;
}

// Largest Container
// You are given an array of numbers, each representing the height of a
// vertical line on a graph. A container can be formed with any pair of
// these lines, along with the x-axis of the graph. Return the amount of
// water which the largest container can hold.
int
largest_container(std::vector<int> const& heights)
{
    int max_water = 0;
    int left = 0;
    int right = heights.size() - 1;

    while (left < right) {
        // calculate the water contained between the current pair of
        // lines
        int water = std::min(heights[left], heights[right]) * (right - left);
        max_water = std::max(max_water, water);

        // move the pointers inward, always moving the pointer at the
        // shorter line. if both lines have the same height, move both
        // pointers inward
        if (heights[left] < heights[right]) {
            ++left;
        } else if (heights[left] > heights[right]) {
            --right;
        } else {
            ++left;
            --right;
        }
    }
    return max_water;
}

// Shift Zeroes to the End
// Given an array of integers, modify the array in place to move all
// zeroes to the end while maintaining the relative order of all
// non-zero elements.
void
shift_zeroes_to_the_end(std::vector<int>& nums)
{
    // the left pointer is used to position non-zero elements
    int left = 0;

    // iterate through the array using a 'right' pointer to locate
    // non-zero elements
    for (std::size_t right = 0; right < nums.size(); ++right) {
        if (nums[right] != 0) {
            std::swap(nums[left], nums[right]);
            // increment 'left' since it now points to a position
            // already occupied by a non-zero element
            ++left;
        }
    }
}

// Next Lexicographical Sequence
std::string
next_lexicographical_sequence(std::string const& str)
{
    std::string letters = str;

    // locate the pivot, which is the first character from the right
    // that breaks non-increasing order. start searching from the
    // second-to-last position, since the last character is neither
    // increasing nor decreasing
    int pivot = letters.size() - 2;
    while (pivot >= 0 && letters[pivot] >= letters[pivot + 1]) {
        --pivot;
    }

    // if pivot is not found, the string is already in its largest
    // permutation. in this case, reverse the string to obtain the
    // smallest permutation
    if (pivot == -1) {
        std::reverse(letters.begin(), letters.end());
        return letters;
    }

    // find the right-most successor to the pivot
    int rightmost_successor = letters.size() - 1;
    while (letters[rightmost_successor] <= letters[pivot]) {
        --rightmost_successor;
    }

    // swap the rightmost successor with the pivot to increase the
    // lexicographical order of the suffix
    std::swap(letters[pivot], letters[rightmost_successor]);

    // reverse the suffix after the pivot to minimize its permutationa
    std::reverse(letters.begin() + pivot + 1, letters.end());
    return letters;
}
