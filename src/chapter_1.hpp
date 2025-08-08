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
            left += 1;
        }
        // if the sum is larger, decrement the right pointer, aiming to
        // decrease the sum toward the target value
        else if (sum > target) {
            right -= 1;
        }
        // if the target pair is found, return its indexes
        else {
            return {left, right};
        }
    }
    return {};
}

