#include "c04_fast_and_slow_pointers.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("chapter 4", "[chapter_4]")
{
    // SECTION("Linked List Reversal")
    // {
    //     // iterative
    //     {
    //         list_node<int>* head = new list_node<int>{1, nullptr};
    //         list_node<int>* node = head;
    //         node->next = new list_node<int>{2, nullptr};
    //         node = node->next;
    //         node->next = new list_node<int>{4, nullptr};
    //         node = node->next;
    //         node->next = new list_node<int>{7, nullptr};
    //         node = node->next;
    //         node->next = new list_node<int>{3, nullptr};

    //         auto new_head = linked_list_reversal_iterative(head);
    //         REQUIRE(new_head->val == 3);
    //         new_head = new_head->next;
    //         REQUIRE(new_head->val == 7);
    //         new_head = new_head->next;
    //         REQUIRE(new_head->val == 4);
    //         new_head = new_head->next;
    //         REQUIRE(new_head->val == 2);
    //         new_head = new_head->next;
    //         REQUIRE(new_head->val == 1);
    //         new_head = new_head->next;
    //         REQUIRE(new_head == nullptr);
    //     }
    //     // recursive
    //     {
    //         list_node<int>* head = new list_node<int>{1, nullptr};
    //         list_node<int>* node = head;
    //         node->next = new list_node<int>{2, nullptr};
    //         node = node->next;
    //         node->next = new list_node<int>{4, nullptr};
    //         node = node->next;
    //         node->next = new list_node<int>{7, nullptr};
    //         node = node->next;
    //         node->next = new list_node<int>{3, nullptr};

    //         auto new_head = linked_list_reversal_recursive(head);
    //         REQUIRE(new_head->val == 3);
    //         new_head = new_head->next;
    //         REQUIRE(new_head->val == 7);
    //         new_head = new_head->next;
    //         REQUIRE(new_head->val == 4);
    //         new_head = new_head->next;
    //         REQUIRE(new_head->val == 2);
    //         new_head = new_head->next;
    //         REQUIRE(new_head->val == 1);
    //         new_head = new_head->next;
    //         REQUIRE(new_head == nullptr);
    //     }
    // }

    // SECTION("Remove kth Last Node")
    // {
    //     list_node<int>* head = new list_node<int>{1, nullptr};
    //     list_node<int>* node = head;
    //     node->next = new list_node<int>{2, nullptr};
    //     node = node->next;
    //     node->next = new list_node<int>{4, nullptr};
    //     node = node->next;
    //     node->next = new list_node<int>{7, nullptr};
    //     node = node->next;
    //     node->next = new list_node<int>{3, nullptr};

    //     auto new_head = remove_kth_last_node(head, 2);
    //     REQUIRE(new_head->val == 1);
    //     new_head = new_head->next;
    //     REQUIRE(new_head->val == 2);
    //     new_head = new_head->next;
    //     REQUIRE(new_head->val == 4);
    //     new_head = new_head->next;
    //     REQUIRE(new_head->val == 3);
    //     new_head = new_head->next;
    //     REQUIRE(new_head == nullptr);
    // }

    // SECTION("Linked List Intersection")
    // {
    //     REQUIRE(linked_list_intersection(nullptr, nullptr) == nullptr);


    //     list_node<int>* head_a = new list_node<int>{1, nullptr};
    //     list_node<int>* node_a = head_a;
    //     node_a->next = new list_node<int>{3, nullptr};
    //     node_a = node_a->next;
    //     node_a->next = new list_node<int>{4, nullptr};
    //     node_a = node_a->next;

    //     list_node<int>* head_b = new list_node<int>{6, nullptr};
    //     list_node<int>* node_b = head_b;
    //     node_b->next = new list_node<int>{4, nullptr};
    //     node_b = node_b->next;

    //     // both lists point to the same nodes (intersection)
    //     list_node<int>* intersection = new list_node<int>{8, nullptr};
    //     list_node<int>* node = intersection;
    //     node_a->next = node;
    //     node_b->next = node;
    //     node->next = new list_node<int>{7, nullptr};
    //     node = node->next;
    //     node->next = new list_node<int>{2, nullptr};

    //     REQUIRE(linked_list_intersection(head_a, head_b)->val == 8);
    // }

    // SECTION("LRU Cache")
    // {
    //     lru_cache cache(3);
    //     cache.put(1, 100);
    //     cache.put(2, 250);
    //     REQUIRE(cache.get(2) == 250);
    //     cache.put(4, 300);
    //     cache.put(3, 200);
    //     REQUIRE(cache.get(4) == 300);
    //     REQUIRE(cache.get(1) == -1);
    // }

    // SECTION("Palindromic Linked List")
    // {
    //     {
    //         list_node<int>* head = new list_node<int>{1, nullptr};
    //         list_node<int>* node = head;
    //         node->next = new list_node<int>{2, nullptr};
    //         node = node->next;
    //         node->next = new list_node<int>{3, nullptr};
    //         node = node->next;
    //         node->next = new list_node<int>{2, nullptr};
    //         node = node->next;
    //         node->next = new list_node<int>{1, nullptr};
    //         REQUIRE(palindromic_linked_list(head));
    //     }

    //     {
    //         list_node<int>* head = new list_node<int>{1, nullptr};
    //         list_node<int>* node = head;
    //         node->next = new list_node<int>{2, nullptr};
    //         node = node->next;
    //         node->next = new list_node<int>{1, nullptr};
    //         node = node->next;
    //         node->next = new list_node<int>{2, nullptr};
    //         REQUIRE_FALSE(palindromic_linked_list(head));
    //     }
    // }

    // SECTION("Flatten Multi-Level Linked List")
    // {
    //     // 1 -> 2 -> 3 -> 4 -> 5
    //     //      |         |
    //     //      6 -> 7    8 -> 9
    //     //           |    |
    //     //          10   11
    //     multi_level_list_node* head = new multi_level_list_node{1, nullptr, nullptr};
    //     auto* node = head;
    //     node->next = new multi_level_list_node{2, nullptr, nullptr};
    //     node = node->next;
    //     node->child = new multi_level_list_node{6, nullptr, nullptr};
    //     node->child->next = new multi_level_list_node{7, nullptr, nullptr};
    //     node->child->next->child = new multi_level_list_node{10, nullptr, nullptr};
    //     node->next = new multi_level_list_node{3, nullptr, nullptr};
    //     node = node->next;
    //     node->next = new multi_level_list_node{4, nullptr, nullptr};
    //     node->child = new multi_level_list_node{8, nullptr, nullptr};
    //     node->child->next = new multi_level_list_node{9, nullptr, nullptr};
    //     node->child->child = new multi_level_list_node{11, nullptr, nullptr};
    //     node = node->next;
    //     node->next = new multi_level_list_node{5, nullptr, nullptr};

    //     auto* new_head = flatten_multi_level_list(head);
    //     for (int i = 1; i <= 11; ++i) {
    //         REQUIRE(new_head->val == i);
    //         new_head = new_head->next;
    //     }
    // }
}
