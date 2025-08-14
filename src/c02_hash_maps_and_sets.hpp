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
                return false;
            }
            if (col_sets[c].contains(num)) {
                return false;
            }
            if (subgrid_sets[r / 3][c / 3].contains(num)) {
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

// Zero Striping
// For each zero in an m x n matrix, set its entire row and column to
// zero in place.
void
zero_striping_hash_sets(std::vector<std::vector<int>>& matrix)
{
    if (matrix.empty() || matrix[0].empty()) {
        return;
    }

    std::unordered_set<int> zero_rows;
    std::unordered_set<int> zero_cols;

    std::size_t m = matrix.size();
    std::size_t n = matrix[0].size();

    // Pass 1: Traverse through the matrix to identify the rows and
    // columns containing zeros and store their indexes in the
    // appropriate hash sets.
    for (std::size_t r = 0; r < m; ++r) {
        for (std::size_t c = 0; c < n; ++c) {
            if (matrix[r][c] == 0) {
                zero_rows.emplace(r);
                zero_cols.emplace(c);
            }
        }
    }

    // Pass 2: Set any cell in the matrix to zero if its row index is in
    // zero_rows or its column index is in zero_cols.
    for (std::size_t r = 0; r < m; ++r) {
        for (std::size_t c = 0; c < n; ++c) {
            if (zero_rows.contains(r) || zero_cols.contains(c)) {
                matrix[r][c] = 0;
            }
        }
    }
}

void
zero_striping(std::vector<std::vector<int>>& matrix)
{
    if (matrix.empty() || matrix[0].empty()) {
        return;
    }

    std::size_t m = matrix.size();
    std::size_t n = matrix[0].size();

    // check if the first row initially contains a zero
    bool first_row_has_zero = false;
    for (std::size_t c = 0; c < n; ++c) {
        if (matrix[0][c] == 0) {
            first_row_has_zero = true;
            break;
        }
    }

    // check if the first column initially contains a zero
    bool first_col_has_zero = false;
    for (std::size_t r = 0; r < m; ++r) {
        if (matrix[r][0] == 0) {
            first_col_has_zero = true;
            break;
        }
    }

    // use the first row and column as markers. if an element in the
    // submatrix is zero, mark its corresponding row and column in the
    // first row and column as 0.
    for (std::size_t r = 0; r < m; ++r) {
        for (std::size_t c = 0; c < n; ++c) {
            if (matrix[r][c] == 0) {
                matrix[0][c] = 0;
                matrix[r][0] = 0;
            }
        }
    }

    // update the submatrix using the markers in the first row and
    // column
    for (std::size_t r = 0; r < m; ++r) {
        for (std::size_t c = 0; c < n; ++c) {
            if (matrix[0][c] == 0 || matrix[r][0] == 0) {
                matrix[r][c] = 0;
            }
        }
    }

    // if the first row had a zero initially, set all elments in the
    // first row to zero
    if (first_row_has_zero) {
        for (std::size_t c = 0; c < n; ++c) {
            matrix[0][c] = 0;
        }
    }

    // if the first column had a zero initially, set all elments in the
    // first column to zero
    if (first_col_has_zero) {
        for (std::size_t r = 0; r < m; ++r) {
            matrix[r][0] = 0;
        }
    }

}
