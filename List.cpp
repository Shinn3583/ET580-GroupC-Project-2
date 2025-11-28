// list.cpp // Zhiyi Chen 11/11 Commit#1
#include "List.h"

// Saqibur Rahman

List::List()
    : head(nullptr), tail(nullptr) {
}

List::~List() {
    Node* n = head;
    Node* backup = nullptr;

    while (n != nullptr) {
        backup = n;
        n = n->next;
        delete backup;
    }

    head = nullptr;
    tail = nullptr;
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
