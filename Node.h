// node.h // Zhiyi Chen 11/11 Commit#1
#ifndef NODE_H
#define NODE_H

// Saqibur Rahman — Phase II Task 5: Node now stores House

#include "House.h"   // Sikder Ishaq Phase II Task 4

class Iterator;   // forward declaration
class List;       // forward declaration

class Node {
private:
    House data;     // was int, now House (Saqibur Phase II Task 5)
    Node* next;     // pointer to the next node

    // friend access from Phase I Step 5
    friend class List;
    friend class Iterator;

public:
    Node();                      
    Node(const House& d);   // changed from int to House
};

#endif
