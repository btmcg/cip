#include <algorithm> // std::sort
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

