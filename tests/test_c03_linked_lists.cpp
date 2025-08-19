#include "c03_linked_lists.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("chapter 3", "[chapter_3]")
{
    SECTION("Linked List Reversal")
    {
        // iterative
        {
            list_node<int>* head = new list_node<int>{1, nullptr};
            list_node<int>* node = head;
            node->next = new list_node<int>{2, nullptr};
            node = node->next;
            node->next = new list_node<int>{4, nullptr};
            node = node->next;
            node->next = new list_node<int>{7, nullptr};
            node = node->next;
            node->next = new list_node<int>{3, nullptr};

            auto new_head = linked_list_reversal_iterative(head);
            REQUIRE(new_head->val == 3);
            new_head = new_head->next;
            REQUIRE(new_head->val == 7);
            new_head = new_head->next;
            REQUIRE(new_head->val == 4);
            new_head = new_head->next;
            REQUIRE(new_head->val == 2);
            new_head = new_head->next;
            REQUIRE(new_head->val == 1);
            new_head = new_head->next;
            REQUIRE(new_head == nullptr);
        }
        // recursive
        {
            list_node<int>* head = new list_node<int>{1, nullptr};
            list_node<int>* node = head;
            node->next = new list_node<int>{2, nullptr};
            node = node->next;
            node->next = new list_node<int>{4, nullptr};
            node = node->next;
            node->next = new list_node<int>{7, nullptr};
            node = node->next;
            node->next = new list_node<int>{3, nullptr};

            auto new_head = linked_list_reversal_recursive(head);
            REQUIRE(new_head->val == 3);
            new_head = new_head->next;
            REQUIRE(new_head->val == 7);
            new_head = new_head->next;
            REQUIRE(new_head->val == 4);
            new_head = new_head->next;
            REQUIRE(new_head->val == 2);
            new_head = new_head->next;
            REQUIRE(new_head->val == 1);
            new_head = new_head->next;
            REQUIRE(new_head == nullptr);
        }
    }

    SECTION("Remove kth Last Node")
    {
        list_node<int>* head = new list_node<int>{1, nullptr};
        list_node<int>* node = head;
        node->next = new list_node<int>{2, nullptr};
        node = node->next;
        node->next = new list_node<int>{4, nullptr};
        node = node->next;
        node->next = new list_node<int>{7, nullptr};
        node = node->next;
        node->next = new list_node<int>{3, nullptr};

        auto new_head = remove_kth_last_node(head, 2);
        REQUIRE(new_head->val == 1);
        new_head = new_head->next;
        REQUIRE(new_head->val == 2);
        new_head = new_head->next;
        REQUIRE(new_head->val == 4);
        new_head = new_head->next;
        REQUIRE(new_head->val == 3);
        new_head = new_head->next;
        REQUIRE(new_head == nullptr);
    }

    SECTION("Linked List Intersection")
    {
        REQUIRE(linked_list_intersection(nullptr, nullptr) == nullptr);


        list_node<int>* head_a = new list_node<int>{1, nullptr};
        list_node<int>* node_a = head_a;
        node_a->next = new list_node<int>{3, nullptr};
        node_a = node_a->next;
        node_a->next = new list_node<int>{4, nullptr};
        node_a = node_a->next;

        list_node<int>* head_b = new list_node<int>{6, nullptr};
        list_node<int>* node_b = head_b;
        node_b->next = new list_node<int>{4, nullptr};
        node_b = node_b->next;

        // both lists point to the same nodes (intersection)
        list_node<int>* intersection = new list_node<int>{8, nullptr};
        list_node<int>* node = intersection;
        node_a->next = node;
        node_b->next = node;
        node->next = new list_node<int>{7, nullptr};
        node = node->next;
        node->next = new list_node<int>{2, nullptr};

        REQUIRE(linked_list_intersection(head_a, head_b)->val == 8);
    }
}
