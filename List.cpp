// Zhiyi Chen 11/11 Commit#1
#include "List.h"

// Saqibur Rahman

List::List()
    : head(nullptr), tail(nullptr) {
}

List::~List() {
    Node* n = head;
    Node* backup = nullptr;

    while (n != nullptr) {
        backup = n;
        n = n->next;
        delete backup;
    }

    head = nullptr;
    tail = nullptr;
}

Iterator List::begin() {
    return Iterator(head);
}

Iterator List::end() {
    return Iterator(nullptr);
}




bool List::empty() {                    //Gabriel adding implementations of functions empty, push front, and print 11/14/25

    return head == nullptr;
}

void List::push_front(int value) {

    Node* n = new Node(value);
    n->next = head;
    head = n;
    
    if (tail == nullptr) {
        tail = n;
    }
    
}

void List::push_back(int value) {           //Gabriel adding push back to cpp 11/14/25

    Node* n = new Node(value);

    if (tail == nullptr) {
        head = tail = n;
    }
    else {
        tail->next = n;
        tail = n;
    }
    
}


void List::print() {

    Node* p = head;

    while (p != nullptr) {
        std::cout << p->data << " " ;
        p = p->next;
    }
    std::cout << std::endl;
}




}



Iterator List::find(int value) { // Sikder Ishaq 11/15: linear search for value
    Node* p = head;
    while (p != nullptr) {
        if (p->data == value) {
            return Iterator(p);
        }
        p = p->next;
    }
    return end();
}