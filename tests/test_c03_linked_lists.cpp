#include "c03_linked_lists.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("chapter 3", "[chapter_3]")
{
    SECTION("Linked List Reversal")
    {
        list_node<int>* node = new list_node<int>{1, nullptr};
        node->next = new list_node<int>{2, nullptr};
        node = node->next;
        node->next = new list_node<int>{4, nullptr};
        node = node->next;
        node->next = new list_node<int>{7, nullptr};
        node = node->next;
        node->next = new list_node<int>{3, nullptr};

        auto new_head = linked_list_reversal_iterative(node);
        REQUIRE(new_head->val == 3);
        new_head = new_head->next;
        REQUIRE(new_head->val == 7);
        new_head = new_head->next;
        REQUIRE(new_head->val == 4);
        // new_head = new_head->next;
        // REQUIRE(new_head->val == 2);
        // new_head = new_head->next;
        // REQUIRE(new_head->val == 1);
        // new_head = new_head->next;
        // REQUIRE(new_head == nullptr);
    }

    // SECTION("Verify Sudoku Board")
    // {
    //     // clang-format off
    //     REQUIRE_FALSE(verify_sudoku_board(std::vector<std::vector<int>>{
    //         { 3, 0, 6,  0, 5, 8,    4, 0, 0 },
    //         { 5, 2, 0,  0, 0, 0,    0, 0, 0 },
    //         { 0, 8, 7,  0, 0, 0,    0, 3, 1 },

    //         { 1, 0, 2,  5, 0, 0,    3, 2, 0 }, // two 2's
    //         { 9, 0, 0,  8, 6, 3,    0, 0, 5 },
    //         { 0, 5, 0,  0, 9, 0,    6, 0, 0 },

    //         { 0, 3, 0,  0, 0, 8,    2, 5, 0 },
    //         { 0, 1, 0,  0, 0, 0,    0, 7, 4 },
    //         { 0, 0, 5,  2, 0, 6,    0, 0, 0 }}));
    //                           // two 8's
    //     REQUIRE(verify_sudoku_board(std::vector<std::vector<int>>{
    //         { 3, 0, 6,  0, 5, 0,    4, 0, 0 },
    //         { 5, 2, 0,  0, 0, 0,    0, 0, 0 },
    //         { 0, 8, 7,  0, 0, 0,    0, 3, 1 },

    //         { 1, 0, 2,  5, 0, 0,    3, 0, 0 },
    //         { 9, 0, 0,  8, 6, 3,    0, 0, 5 },
    //         { 0, 5, 0,  0, 9, 0,    6, 0, 0 },

    //         { 0, 3, 0,  0, 0, 8,    2, 5, 0 },
    //         { 0, 1, 0,  0, 0, 0,    0, 7, 4 },
    //         { 0, 0, 5,  2, 0, 6,    0, 0, 0 }}));
    //     REQUIRE_FALSE(verify_sudoku_board(std::vector<std::vector<int>>{
    //         { 3, 0, 6,  0, 5, 0,    4, 0, 0 },
    //         { 5, 2, 0,  0, 0, 0,    0, 0, 3 }, // subgrid has two 3's
    //         { 0, 8, 7,  0, 0, 0,    0, 3, 1 },

    //         { 1, 0, 2,  5, 0, 0,    3, 0, 0 },
    //         { 9, 0, 0,  8, 6, 3,    0, 0, 5 },
    //         { 0, 5, 0,  0, 9, 0,    6, 0, 0 },

    //         { 0, 3, 0,  0, 0, 8,    2, 5, 0 },
    //         { 0, 1, 0,  0, 0, 0,    0, 7, 4 },
    //         { 0, 0, 5,  2, 0, 6,    0, 0, 0 }}));
    //     // clang-format on
    // }

    // SECTION("Zero Striping")
    // {
    //     {
    //         // clang-format off
    //         std::vector<std::vector<int>> matrix
    //         {
    //             {1,   2,  3, 4,   5},
    //             {6,   0,  8, 9,  10},
    //             {11, 12, 13, 14, 15},
    //             {16, 17, 18, 19,  0}
    //         };
    //         // clang-format on
    //         zero_striping_hash_sets(matrix);

    //         // row 1
    //         for (std::size_t r = 1, c = 0; c < matrix[0].size(); ++c) {
    //             REQUIRE(matrix[r][c] == 0);
    //         }

    //         // row 3
    //         for (std::size_t r = 3, c = 0; c < matrix[0].size(); ++c) {
    //             REQUIRE(matrix[r][c] == 0);
    //         }

    //         // col 1
    //         for (std::size_t r = 0, c = 1; r < matrix.size(); ++r) {
    //             REQUIRE(matrix[r][c] == 0);
    //         }

    //         // col 4
    //         for (std::size_t r = 0, c = 4; r < matrix.size(); ++r) {
    //             REQUIRE(matrix[r][c] == 0);
    //         }
    //     }

    //     {
    //         // clang-format off
    //         std::vector<std::vector<int>> matrix
    //         {
    //             {1,   2,  0, 4,   5},
    //             {6,   0,  8, 9,  10},
    //             {11, 12, 13, 14, 15},
    //             {16, 17, 18, 19,  0}
    //         };
    //         // clang-format on
    //         zero_striping(matrix);

    //         // row 0
    //         for (std::size_t r = 0, c = 0; c < matrix[0].size(); ++c) {
    //             REQUIRE(matrix[r][c] == 0);
    //         }

    //         // row 1
    //         for (std::size_t r = 1, c = 0; c < matrix[0].size(); ++c) {
    //             REQUIRE(matrix[r][c] == 0);
    //         }

    //         // row 3
    //         for (std::size_t r = 3, c = 0; c < matrix[0].size(); ++c) {
    //             REQUIRE(matrix[r][c] == 0);
    //         }

    //         // col 1
    //         for (std::size_t r = 0, c = 1; r < matrix.size(); ++r) {
    //             REQUIRE(matrix[r][c] == 0);
    //         }

    //         // col 2
    //         for (std::size_t r = 0, c = 2; r < matrix.size(); ++r) {
    //             REQUIRE(matrix[r][c] == 0);
    //         }

    //         // col 4
    //         for (std::size_t r = 0, c = 4; r < matrix.size(); ++r) {
    //             REQUIRE(matrix[r][c] == 0);
    //         }
    //     }

    // }
}
