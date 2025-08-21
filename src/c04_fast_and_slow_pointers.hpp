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

struct list_node
{
    int val;
    list_node* next = nullptr;
};


// Linked List Loop
// Given a singly linked list, determine if it contains a cycle. A cycle
// occurs if a node's next pointer references an earlier node in the
// list, causing a loop.
bool linked_list_loop(list_node* head) {
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
