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

template <typename T>
struct list_node
{
    T val;
    list_node* next = nullptr;
};


// Linked List Reversal
// Reverse a singly linked list.
list_node<int>*
linked_list_reversal_iterative(list_node<int>* head)
{
    list_node<int>* curr_node = head;
    list_node<int>* prev_node = nullptr;

    // reverse the direction of each node's pointer until 'curr_node' is
    // nullptr
    while (curr_node != nullptr) {
        list_node<int>* next_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }
    // 'prev_node' will be pointing at the head of the reversed linked
    // list
    return prev_node;
}

list_node<int>*
linked_list_reversal_recursive(list_node<int>* head)
{
    // base case
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    // recursively reverse the sublist starting from the next node
    list_node<int>* new_head = linked_list_reversal_recursive(head->next);
    // connect the reversed linked list to the head node to fully
    // reverse the entire linked list
    head->next->next = head;
    head->next = nullptr;
    return new_head;
}

// Remove the kth Last Node From a Linked List
// Return the head of a singly linked list after removing the kth node
// from the end of it.
list_node<int>*
remove_kth_last_node(list_node<int>* head, int k)
{
    // a dummy node to ensure there's a node before 'head' in case we
    // need to remove the head node
    list_node<int> dummy{-1, head};
    list_node<int>* trailer = &dummy;
    list_node<int>* leader = &dummy;

    // advance 'leader' k steps ahead
    for (int i = 0; i < k; ++i) {
        leader = leader->next;
        // if k is larger than the length of the linked list, no node
        // needs to be removed
        if (leader == nullptr) {
            return head;
        }
    }

    // move 'leader' to the end of the linked list, keeping 'trailer' k
    // nodes behind
    while (leader->next != nullptr) {
        leader = leader->next;
        trailer = trailer->next;
    }

    // remove the kth node from the end
    list_node<int>* tmp = trailer->next;
    trailer->next = trailer->next->next;
    delete tmp;
    return dummy.next;
}
