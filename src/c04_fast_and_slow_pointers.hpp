#include <algorithm> // std::sort
#include <array>
#include <cctype> // std::isalnum
#include <cmath>  // std::floor, std::pow
#include <print>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility> // std::pair
#include <vector>

struct list_node
{
    int val;
    list_node* next = nullptr;
};


// Linked List Loop
// Given a singly linked list, determine if it contains a cycle. A cycle
// occurs if a node's next pointer references an earlier node in the
// list, causing a loop.
bool
linked_list_loop(list_node* head)
{
    list_node* slow = head;
    list_node* fast = head;

    // check both 'fast' and 'fast.next' to avoid null pointer
    // exceptions when we perform 'fast.next' and 'fast.next.next'.
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow) {
            return true;
        }
    }
    return false;
}

// Linked List Midpoint
// Given a singly linked list, find and return it's middle node. If
// there are two middle nodes, return the second one.
list_node*
linked_list_midpoint(list_node* head)
{
    list_node* slow = head;
    list_node* fast = head;

    // when the fast pointer reaches the end of the list, the slow
    // pointer willbe at the midpoint of the linked list.
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Happy Number
// In number theory, a happy number is defined as a number that, when
// repeatedly subjected to the process of squaring its digits and
// summing those square, eventually leads to 1. An unhappy number will
// never reach 1 during this process, and will get stuck in an infinite
// loop.
//
// Given an integer, determine if it's a happy number.
int
get_next_num(int x)
{
    int next_num = 0;
    while (x > 0) {
        // extract the last digit of x
        int digit = x % 10;
        // truncate (remove) the last digit from 'x' using floor
        // division
        x = static_cast<int>(std::floor(x / 10));
        // add the square of the extracted digit to the sum
        next_num += std::pow(digit, 2);
    }
    return next_num;
}

bool
happy_number(int n)
{
    int slow = n;
    int fast = n;

    while (true) {
        slow = get_next_num(slow);
        fast = get_next_num(get_next_num(fast));
        if (fast == 1) {
            return true;
        }
        // if the fast and slow pointers meet, a cycle is detected.
        // Hence, 'n' is not a happy number.
        else if (fast == slow) {
            return false;
        }
    }

    return false;
}
