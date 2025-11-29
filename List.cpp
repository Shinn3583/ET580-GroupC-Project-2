// list.cpp // Zhiyi Chen 11/11 Commit#1
#include "List.h"

// Saqibur Rahman

List::List()
    : head(nullptr), tail(nullptr), size(0) {       //Gabriel Phase III updating constructor by adding size 11/28/25
}

List::~List() {
    clear();  // Zhiyi Chen PHASE 3 STEP 5: Use clear() instead of manual deletion
}

Iterator List::begin() {
    return Iterator(head);
}

Iterator List::end() {
    return Iterator(nullptr);
}

// Gabriel implementation preserved
bool List::empty() {
    return head == nullptr;
}

// Saqibur Rahman — Phase II Task 5
House& List::front() {
    return head->data;
}

// Gabriel push_front updated by Saqibur
void List::push_front(const House& value) {

    Node* n = new Node(value);
    n->next = head;
    head = n;

    if (tail == nullptr) {
        tail = n;
    }

    size++;             //Gabriel Phase III adding increment operation to function 11/28/25
}

// Gabriel push_back updated by Saqibur
void List::push_back(const House& value) {

    Node* n = new Node(value);

    if (tail == nullptr) {
        head = tail = n;
    }
    else {
        tail->next = n;
        tail = n;
    }

    size++;     //Gabriel Phase III adding increment operation to function 11/28/25
}

void List::pop_front() {
    // Sikder Ishaq — remove head node and update tail if list becomes empty
    if (head == nullptr) return;
    Node* n = head;
    head = head->next;
    if (head == nullptr) tail = nullptr;
    delete n;
    size--;         //Gabriel Phase III adding decrement operation to function 11/28/25
}

Iterator List::insertAfter(Iterator it, const House& value) {
    // Sikder Ishaq — insert new node immediately after iterator's current node
    Node* curr = it.current;
    if (curr == nullptr) return end();
    Node* n = new Node(value);
    n->next = curr->next;
    curr->next = n;
    if (tail == curr) tail = n;

    size++;                 //Gabriel Phase III adding increment operation to function 11/28/25
    return Iterator(n);
}

Iterator List::eraseAfter(Iterator it) {
    // Sikder Ishaq — erase node immediately after iterator's current node
    Node* curr = it.current;
    if (curr == nullptr || curr->next == nullptr) return end();
    Node* target = curr->next;
    curr->next = target->next;
    if (target == tail) tail = curr;
    Iterator result(curr->next);
    delete target;
    size--;                 //Gabriel Phase III adding decrement operation to function 11/28/25

    return result;
}

// Saqibur Rahman — Phase II Task 5: print using House::print()
void List::print() {

    Node* p = head;

    while (p != nullptr) {
        p->data.print();
        std::cout << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

// Sikder Ishaq find modified for House
Iterator List::find(const House& value) {

    Node* p = head;

    while (p != nullptr) {
        if (equivalence(p->data, value)) {   // House equivalence
            return Iterator(p);
        }
        p = p->next;
    }
    return end();
}

// Implemented duplicate: Sikder Phase 2
void List::duplicate(List &other) const {
    // Clear 'other' list
    Node* p = other.head;
    while (p != nullptr) {
        Node* tmp = p;
        p = p->next;
        delete tmp;
    }
    other.head = nullptr;
    other.tail = nullptr;

    // Copy nodes from this list
    Node* src = head;
    Node* last = nullptr;
    while (src != nullptr) {
        Node* n = new Node(src->data); // copy House by value
        if (last == nullptr) {
            other.head = n;
        } else {
            last->next = n;
        }
        last = n;
        src = src->next;
    }
    other.tail = last;
}

// Function: getSize
// Author: Saqibur Rahman — Phase III Task 4
// Description: Returns the current number of nodes stored in the list.
int List::getSize() const {
    return size;
}

// Zhiyi Chen PHASE 3 STEP 5: Clear function implementation

void List::clear() {
    Node* current = head;
    Node* nextNode = nullptr;

    // Delete all nodes
    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }

    // Reset pointers and size
    head = nullptr;
    tail = nullptr;
    size = 0;
}

// Sikder Ishaq — Phase III Task 6
// Algorithm: sortedInsert
// Inserts House 'd' into 'list' maintaining sorted order based on 'comparator'.
// comparator=true  -> small to large; comparator=false -> large to small.
void List::sortedInsert(List &list, const House &d, bool comparator) {
    // Case: empty list or insert before head
    if (list.head == nullptr || compare(d, list.head->data, comparator)) {
        list.push_front(d);
        return;
    }

    // Traverse until the correct position (after nodes that should come before 'd')
    Node* prev = list.head;
    Node* curr = list.head->next;
    while (curr != nullptr && compare(curr->data, d, comparator)) {
        prev = curr;
        curr = curr->next;
    }

    // Insert between prev and curr (or at tail)
    Iterator it(prev);
    list.insertAfter(it, d);
}

// Sikder Ishaq — Phase III Task 6
// Algorithm: binarySearch
// Performs binary search for House 'd' in a sorted 'list' according to 'comparator'.
// Returns Iterator to the found node; otherwise returns end().
Iterator List::binarySearch(List &list, const House &d, bool comparator) {
    int low = 0;
    int high = list.size - 1;

    // Helper to access node by index (walk from head)
    auto nodeAt = [&](int index) -> Node* {
        Node* p = list.head;
        for (int i = 0; i < index && p != nullptr; ++i) {
            p = p->next;
        }
        return p;
    };

    while (low <= high) {
        int mid = low + (high - low) / 2;
        Node* m = nodeAt(mid);
        if (m == nullptr) break;  // safety

        // Check for exact match using equivalence
        if (equivalence(m->data, d)) {
            return Iterator(m);
        }

        // Decide search side based on sort order
        if (compare(m->data, d, comparator)) {
            low = mid + 1;   // go right
        } else {
            high = mid - 1;  // go left
        }
    }
    return list.end();
}
