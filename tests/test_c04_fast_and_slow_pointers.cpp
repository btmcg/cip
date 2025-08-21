#include "c04_fast_and_slow_pointers.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("chapter 4", "[chapter_4]")
{
    SECTION("Linked List Loop")
    {
        // no cycle
        {
            list_node* head = new list_node{1, nullptr};
            list_node* node = head;
            node->next = new list_node{2, nullptr};
            node = node->next;
            node->next = new list_node{3, nullptr};
            node = node->next;
            node->next = new list_node{4, nullptr};
            node = node->next;
            node->next = new list_node{5, nullptr};

            REQUIRE_FALSE(linked_list_loop(head));
        }

        // delayed cycle
        {
            list_node* head = new list_node{1, nullptr};
            list_node* node = head;
            node->next = new list_node{2, nullptr};
            node = node->next;
            node->next = new list_node{3, nullptr};
            list_node* node_three = node->next;
            node = node->next;
            node->next = new list_node{4, nullptr};
            node = node->next;
            node->next = node_three;

            REQUIRE(linked_list_loop(head));
        }

        // complete cycle
        {
            list_node* head = new list_node{1, nullptr};
            list_node* node = head;
            node->next = new list_node{2, nullptr};
            node = node->next;
            node->next = new list_node{3, nullptr};
            node = node->next;
            node->next = new list_node{4, nullptr};
            node = node->next;
            node->next = head;

            REQUIRE(linked_list_loop(head));
        }
    }

    SECTION("Linked List Midpoint")
    {
        REQUIRE(linked_list_midpoint(nullptr) == nullptr);

        // odd number of nodes
        {
            list_node* head = new list_node{1, nullptr};
            list_node* node = head;
            node->next = new list_node{2, nullptr};
            node = node->next;
            node->next = new list_node{3, nullptr};
            node = node->next;
            node->next = new list_node{4, nullptr};
            node = node->next;
            node->next = new list_node{5, nullptr};

            REQUIRE(linked_list_midpoint(head)->val == 3);
        }

        // even number of nodes
        {
            list_node* head = new list_node{1, nullptr};
            list_node* node = head;
            node->next = new list_node{2, nullptr};
            node = node->next;
            node->next = new list_node{3, nullptr};
            node = node->next;
            node->next = new list_node{4, nullptr};

            REQUIRE(linked_list_midpoint(head)->val == 3);
        }
    }

    SECTION("Happy Number") {
        REQUIRE_FALSE(happy_number(0));
        REQUIRE(happy_number(23));
        REQUIRE_FALSE(happy_number(116));
    }
}
