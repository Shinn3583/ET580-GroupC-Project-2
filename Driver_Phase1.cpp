//Zhiyi Chen 11/11 Commit#1
#include <iostream>
#include "List.h"
//Gabriel adding main functions and updating driver file 11/14/25
// Sikder Ishaq 11/15: Phase I tasks 8 & 9 with find only

int main() {
    List L;

    std::cout << "List initially empty? " << (L.empty() ? "yes" : "no") << "\n"; //Sikder
    std::cout << "Pushing front values 10, 20, 30...\n";                //Gabriel adding the push front and print 11/14/25
    L.push_front(10);
    L.push_front(20);
    L.push_front(30);

    std::cout << "List contents: ";
    L.print();

    std::cout << "Pushing back values 40, 50...\n";
    L.push_back(40);
    L.push_back(50);

    std::cout << "List contents: ";
    L.print();

// Sikder Phase 1 
     // Traverse via iterator
    std::cout << "Traverse with iterator: ";
    for (Iterator it = L.begin(); it.hasNext(); it.next()) {
        std::cout << it.getData() << ' ';
    }
    std::cout << "\n";

    // Demonstrate find
    Iterator pos = L.find(20);
    if (pos.hasNext()) {
        std::cout << "Found value: " << pos.getData() << "\n";
    } else {
        std::cout << "Value not found.\n";
    }

    std::cout << "Phase I completed. \n";
    return 0;
}
