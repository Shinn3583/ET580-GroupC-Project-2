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

    bool empty();                           //Gabriel adding member functions step 6: empty, push front, and print 11/14/25
    int& front();
    void push_front(int value);
    void push_back(int value);              //Gabriel adding member function push back 11/14/25
    //Zhiyi added functions
    void pop_front();
    Iterator insertAfter(Iterator it, const int value);
    Iterator eraseAfter(Iterator it);
    Iterator begin();                         // iterator pointing to first node
    Iterator end();                          // iterator pointing past the end (nullptr)
    Iterator find(int value);
    void duplicate(List &other) const;
    void print();


    friend class Iterator;
 
};

#endif
