// iterator.h  // Zhiyi Chen 11/11 Commit#1
#ifndef ITERATOR_H
#define ITERATOR_H

#include "Node.h"

// Saqibur Rahman

class Iterator {
private:
    Node* current;

    // Phase I Step 5
    friend class List;

public:
    explicit Iterator(Node* start);

    void next();
    bool hasNext() const;

    // Saqibur Rahman — Phase II Task 5: return House instead of int
    House& getData();
};

#endif
