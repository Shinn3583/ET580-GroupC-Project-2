// Zhiyi Chen 11/11 Commit#1
#ifndef NODE_H
#define NODE_H

// Saqibur Rahman

class Iterator;   // forward declaration
class List;       // forward declaration

class Node {
private:
    int data;     // stores the value
    Node* next;   // pointer to the next node


public:
    Node();               // default constructor
    Node(const int& d);   // parameterized constructor
};

    // Future steps: List and Iterator will need access to these
    friend class List;
    friend class Iterator;
#endif
