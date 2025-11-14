// Zhiyi Chen 11/11 Commit#1
#ifndef LIST_H
#define LIST_H

#include "Node.h"
#include "Iterator.h"
#include <iostream>

// Saqibur Rahman

class List {
private:
    Node* head;   // pointer to first node
    Node* tail;   // pointer to last node

public:
    List();       // construct an empty list
    ~List();      // destructor: safely delete all nodes

    Iterator begin();   // iterator pointing to first node
    Iterator end();     // iterator pointing past the end (nullptr)
};

#endif
