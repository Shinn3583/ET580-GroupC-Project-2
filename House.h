// Sikder Ishaq — Phase II Task 4: Complex Data Type (House)
// Encapsulated class with constructors, accessors, mutators, and print.
// Non-member functions: equivalence and compare.
#ifndef HOUSE_H
#define HOUSE_H

#include <iostream>

class House {
private:
    int size;   // foundation area in square feet
    int year;   // 4-digit year

public:
    House();                // default: size=0, year=2000
    House(int s, int y);    // parameter: initialize to specified values

    // Accessors (const)
    int getSize() const;
    int getYear() const;

    // Mutators
    void setSize(int s);
    void setYear(int y);

    // Print data members (const)
    void print() const;
};

// Non-member: data equivalence (both size and year equal)
bool equivalence(const House& o1, const House& o2);

// Non-member: compare sizes with order determined by comparator
// comparator=true  -> small to large (o1.size <= o2.size)
// comparator=false -> large to small (o1.size >= o2.size)
bool compare(const House& o1, const House& o2, bool comparator);

#endif // HOUSE_H