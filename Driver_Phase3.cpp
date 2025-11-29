// driver_phase3.cpp // Sikder Ishaq — Phase III Task 1 driver file
// Minimal driver created 
#include <iostream>
#include "List.h"
#include "House.h"

using namespace std;

int main() {
    // Intentionally empty: Phase 3 testing will be added in later 

    // Saqibur Rahman — Phase III Task 4: Testing List::getSize()

    cout << "=== Phase III Task 4: Testing getSize() ===" << endl;

    List houses;

    // Test 1: empty list size
    cout << "Initial size (expect 0): " << houses.getSize() << endl;

    // Test 2: manually add the same data as in data.csv
    houses.push_back(House(700, 1920));
    houses.push_back(House(900, 1940));
    houses.push_back(House(1200, 1950));
    houses.push_back(House(1800, 1980));
    houses.push_back(House(2100, 2010));

    cout << "Size after inserting 5 houses (expect 5): " << houses.getSize() << endl;

    cout << "List contents:" << endl;
    houses.print();

    // Test 3: remove one house and check size again
    houses.pop_front();
    cout << "Size after one pop_front (expect 4): " << houses.getSize() << endl;

    return 0;
}
