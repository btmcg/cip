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

// Linked List Intersection
// Return the node where two singly linked lists intersect. If the
// linked lists don't intersect, return nullptr;
list_node<int>*
linked_list_intersection(list_node<int>* head_a, list_node<int>* head_b)
{
    list_node<int>* ptr_a = head_a;
    list_node<int>* ptr_b = head_b;

    // traverse through list a with 'ptr_a' and list b with 'ptr_b'
    // until they meet
    while (ptr_a != ptr_b) {
        // traverse list a -> list b by first traversing 'ptr_a' and
        // then, upon reaching the end of list a, continue the traversal
        // from the head of list b
        if (ptr_a != nullptr) {
            ptr_a = ptr_a->next;
        } else {
            ptr_a = head_b;
        }

        // simultaneously, traverse list b -> list a
        if (ptr_b != nullptr) {
            ptr_b = ptr_b->next;
        } else {
            ptr_b = head_a;
        }
    }

    // at this point, 'ptr_a' and 'ptr_b' either point to the
    // intersection node or both are nullptr if the lists do not
    // intersect. return either pointer.
    return ptr_a;
}

// LRU Cache
// Design and implement a data structure for the Least Recently Used
// (LRU) cache that supports the following operations:
//      - LRUCache(int capacity) - Initialize an LRU cache with the
//      specified capacity.
//      - int get(int key) - Return the value associated with a key.
//      Return -1 if the key doesn't exist.
//      - void put(int key, int value) - Add a key and its value to the
//      cache. If adding the key would result in the cache exceeding its
//      size capacity, evict the least recently used element. If the key
//      already exists in the cache, update its value.
struct doubly_linked_list_node
{
    int key;
    int val;
    doubly_linked_list_node* prev = nullptr;
    doubly_linked_list_node* next = nullptr;
};

class lru_cache
{
private:
    std::size_t capacity_;
    std::unordered_map<int, doubly_linked_list_node*> hash_map_;
    doubly_linked_list_node* head_ = nullptr;
    doubly_linked_list_node* tail_ = nullptr;

public:
    lru_cache(std::size_t capacity)
            : capacity_(capacity)
            , hash_map_()
            , head_(new doubly_linked_list_node{-1, -1})
            , tail_(new doubly_linked_list_node{-1, -1})
    {
        head_->next = tail_;
        tail_->prev = head_;
    }

    int
    get(int key)
    {
        auto itr = hash_map_.find(key);
        if (itr == hash_map_.end()) {
            return -1;
        }

        // to make this key the most recently used, remove its node and
        // re-add it to the tail of the linked list
        auto& [_, node] = *itr;
        remove_node(node);
        add_to_tail(node);
        return node->val;
    }

    void
    put(int key, int value)
    {
        // if a node with this key already exists, remove it from the
        // linked list
        auto itr = hash_map_.find(key);
        if (itr != hash_map_.end()) {
            remove_node(itr->second);
        }
        auto* node = new doubly_linked_list_node{key, value};
        hash_map_.emplace(key, node);

        // remove the least recently used node from the cache if adding
        // this new node will result in an overflow.
        if (hash_map_.size() > capacity_) {
            auto* to_delete = hash_map_[head_->next->key];
            hash_map_.erase(head_->next->key);
            remove_node(to_delete);
            delete to_delete;
        }
        add_to_tail(node);
    }

private:
    void
    add_to_tail(doubly_linked_list_node* node)
    {
        auto prev_node = tail_->prev;
        node->prev = prev_node;
        node->next = tail_;
        prev_node->next = node;
        tail_->prev = node;
    }

    void
    remove_node(doubly_linked_list_node* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
};

// Palindromic Linked List
// Given the head of a singly linked list, determine if it's a
// palindrome.
list_node<int>*
find_middle(list_node<int>* head)
{
    auto* slow = head;
    auto* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

bool
palindromic_linked_list(list_node<int>* head)
{
    // find the middle of the linked list and then reverse the second
    // half of the linked list starting at this midpoint
    auto* mid = find_middle(head);
    auto* second_head = linked_list_reversal_recursive(mid);

    // compare the first half and reversed second half of the linked
    // list
    auto* ptr1 = head;
    auto* ptr2 = second_head;
    bool result = true;
    while (ptr2 != nullptr) {
        if (ptr1->val != ptr2->val) {
            result = false;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return result;
}
