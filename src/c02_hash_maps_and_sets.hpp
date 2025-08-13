#include <algorithm> // std::sort
#include <cctype>    // std::isalnum
#include <print>
#include <string>
#include <tuple>
#include <unordered_map> // std::pair
#include <utility>       // std::pair
#include <vector>


// Pair Sum - Unsorted
// Given an array of integers, return the indexes of any two numbers
// that add up to a target. The order of the indexes in the result
// doesn't matter. If no pair is found, return an empty array.
std::vector<std::pair<int, int>>
pair_sum_unsorted(std::vector<int> const& nums, int target)
{
    std::vector<std::pair<int, int>> result;
    std::unordered_map<int, int> hashmap;

    for (std::size_t i = 0; i < nums.size(); ++i) {
        if (hashmap.contains(target - nums[i])) {
            result.push_back({hashmap[target - nums[i]], i});
            return result;
        }
        hashmap.emplace(nums[i], i);
    }
    return {};
}
