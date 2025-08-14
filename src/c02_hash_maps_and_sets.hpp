#include <algorithm> // std::sort
#include <array>
#include <cctype> // std::isalnum
#include <print>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility> // std::pair
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


// Verify Sudoku Board
// Given a partially completed 9x9 Sudoku board, determine if the
// current state of the board adheres to the rules of the game:
// -    Each row and column must contain unique numbers between 1 and 9,
//      or be empty (represented by 0).
// -    Each of the nine 3x3 subgrids that compose the grid must
//      contain unique numbers between 1 and 9, or be empty.
bool
verify_sudoku_board(std::vector<std::vector<int>> const& board)
{
    // create hash sets for each row, column, and subgrid to keep track
    // of numbers previously seen on any given row, column, or subgrid
    std::array<std::unordered_set<int>, 9> row_sets;
    std::array<std::unordered_set<int>, 9> col_sets;
    std::array<std::array<std::unordered_set<int>, 3>, 3> subgrid_sets;

    for (std::size_t r = 0; r < row_sets.size(); ++r) {
        for (std::size_t c = 0; c < col_sets.size(); ++c) {
            int num = board[r][c];
            if (num == 0) {
                continue;
            }
            // check if num has been seen in the current row, column, or
            // subgrid
            if (row_sets[r].contains(num)) {
                std::println("row {}", r);
                return false;
            }
            if (col_sets[c].contains(num)) {
                std::println("col {}", r);
                return false;
            }
            if (subgrid_sets[r / 3][c / 3].contains(num)) {
                std::println("subgrid[{}][{}], num={}", r / 3, c / 3, num);
                return false;
            }

            // if we passed the above checks, mark this value as seen by
            // adding it to its corresponding hash sets
            row_sets[r].emplace(num);
            col_sets[c].emplace(num);
            subgrid_sets[r / 3][c / 3].emplace(num);
        }
    }
    return true;
}
