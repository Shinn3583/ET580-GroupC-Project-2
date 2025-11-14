// Zhiyi Chen 11/11 Commit#1
#include "Iterator.h"

// Saqibur Rahman

Iterator::Iterator(Node* start)
    : current(start) {
}

void Iterator::next() {
    if (current != nullptr) {
        current = current->next;
    }
}

bool Iterator::hasNext() const {
    return current != nullptr;
}

int& Iterator::getData() {
    return current->data;
}
