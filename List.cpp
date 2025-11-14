// Zhiyi Chen 11/11 Commit#1
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
