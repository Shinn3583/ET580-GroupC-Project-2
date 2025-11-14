// Zhiyi Chen 11/11 Commit#1
#ifndef ITERATOR_H
#define ITERATOR_H

#include "Node.h"

// Saqibur Rahman

class Iterator {
private:
    Node* current;     // target node

    // Future: List class will need access to Iterator internals
    friend class List;

public:
    explicit Iterator(Node* start);  // point iterator to specific node

    void next();              // advance iterator to next node
    bool hasNext() const;     // true if current != nullptr
    int& getData();           // reference to current node's data
};

#endif
