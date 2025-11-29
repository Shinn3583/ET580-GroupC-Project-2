// list.h // Zhiyi Chen 11/11 Commit#1
#ifndef LIST_H
#define LIST_H

#include "Node.h"
#include "Iterator.h"
#include <iostream>

// Saqibur Rahman

class List {
private:
    Node* head;
    Node* tail;

    int size;         //Gabriel Phase III step 3: adding size data member to track nodes 11/28/25


public:
    List();
    ~List();

    bool empty();   // Gabriel

    // Saqibur Rahman — Phase II Task 5
    House& front();

    void push_front(const House& value);  // changed to House
    void push_back(const House& value);   // changed to House

    void pop_front();
    Iterator insertAfter(Iterator it, const House& value);
    Iterator eraseAfter(Iterator it);

    Iterator begin();
    Iterator end();

    // Sikder’s find adapted by Saqibur
    Iterator find(const House& value);

    void duplicate(List &other) const;
    void print();

    // Saqibur Rahman — Phase III Task 4
    int getSize() const;

    // PHASE 3 STEP 5: Clear function - Zhiyi Chen
    void clear();

    friend class Iterator;
};

#endif
