// Sikder Ishaq — Phase II Task 4 Implementation
// Defines member and non-member functions for House.
#include "House.h"

// Constructors
House::House() : size(0), year(2000) {}
House::House(int s, int y) : size(s), year(y) {}

// Accessors
int House::getSize() const { return size; }
int House::getYear() const { return year; }

// Mutators
void House::setSize(int s) { size = s; }
void House::setYear(int y) { year = y; }

// Print
void House::print() const {
    std::cout << "House(size=" << size << ", year=" << year << ")";
}

// Non-member implementations
bool equivalence(const House& o1, const House& o2) {
    return o1.getSize() == o2.getSize() && o1.getYear() == o2.getYear();
}

bool compare(const House& o1, const House& o2, bool comparator) {
    if (comparator) {
        return o1.getSize() <= o2.getSize();
    } else {
        return o1.getSize() >= o2.getSize();
    }
}