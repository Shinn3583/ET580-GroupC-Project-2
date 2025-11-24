//Zhiyi Chen 11/11 Commit#1
//  Phase I Driver Updated 
#include <iostream>
#include "List.h"
#include "House.h"

//Gabriel adding main functions and updating driver file 11/14/25
// Sikder Ishaq 11/15: Phase I tasks 8 & 9 with find only

int main() {
    List L;
   // Empty check
    std::cout << "List initially empty? " << (L.empty() ? "Yes" : "No") << '\n';

    // Push front (two houses)
    L.push_front(House(1200, 2005));
    L.push_front(House(800, 1995));


      // Push back (two houses)
    L.push_back(House(1500, 2010));
    L.push_back(House(1800, 2015));


    // Print list
    std::cout << "List contents: ";
    L.print();

    // Front element
    std::cout << "Front element: ";
    L.front().print();

    // Traverse via iterator
    std::cout << "Traverse with iterator:\n";
    for (Iterator it = L.begin(); it.hasNext(); it.next()) {
        it.getData().print();
    }

    // Demonstrate find (existing)
    std::cout << "Find (1500,2010): ";
    Iterator pos = L.find(House(1500, 2010));
    if (pos.hasNext()) {
        std::cout << "Found: ";
        pos.getData().print();
    } else {
        std::cout << "Not found\n";
    }

    // Demonstrate find (missing)
    std::cout << "Find (9999,1999): ";
    Iterator miss = L.find(House(9999, 1999));
    if (miss.hasNext()) {
        std::cout << "Found: ";
        miss.getData().print();
    } else {
        std::cout << "Not found\n";
    }

    std::cout << "Phase I completed.\n";
    return 0;
}
