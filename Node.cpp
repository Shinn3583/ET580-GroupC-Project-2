// node.cpp // Zhiyi Chen 11/11 Commit#1
#include "Node.h"

// Saqibur Rahman — Phase II Task 5 implementation

Node::Node()
    : data(House()), next(nullptr) {
}

Node::Node(const House& d)
    : data(d), next(nullptr) {
}
