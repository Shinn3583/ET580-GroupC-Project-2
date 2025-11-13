//Zhiyi Chen 11/11 Commit#1
#ifndef ITERATOR_H
#define ITERATOR_H
#include "Node.h"
// Saqibur Rahman 

class Iterator {
private:
    Node* current;

public:
Iterator(Node* start);
    Iterator& operator++();
   
};

#endif