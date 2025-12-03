//Zhiyi Chen 11/18 Commit#11
#include <iostream>
#include "List.h"                   //Gabriel Sencion 11/22 commit 15 adding read function
#include <fstream>
#include <sstream>
#include "House.h"
using namespace std;
//Reads Houses from data.csv loads them into List
void read(List& myList) {
    std::ifstream fin("data.csv");
    if (!fin) {
        std::cerr << "Error: Could not open data.csv \n";
        return;
    }

    std::string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string token;

        int size = 0;
        int year = 0;

        //Read size from data
        getline(ss, token, ',');
        size = std::stoi(token);

        //Read year from data
        getline(ss, token, ',');
        year = std::stoi(token);

        //Creating object of House
        House h(size, year);

        //Add to list
        myList.push_back(h);
    }
    
    
}

// Test House class functionality
void testHouseClass() {
    cout << "=== TESTING HOUSE CLASS ===" << endl;
    
    // Test default constructor
    House house1;
    cout << "Default House: ";
    house1.print();
    
    // Test parameter constructor
    House house2(1500, 2005);
    cout << "Parameter House: ";
    house2.print();
    
    // Test accessor functions
    cout << "Accessors - Size: " << house2.getSize() 
         << ", Year: " << house2.getYear() << endl;
    
    // Test mutator functions
    house1.setSize(1200);
    house1.setYear(2010);
    cout << "After mutators: ";
    house1.print();
    cout << endl;
}

// Test utility functions
void testUtilityFunctions() {
    cout << "=== TESTING UTILITY FUNCTIONS ===" << endl;
    
    House house1(1200, 2000);
    House house2(1200, 2000);
    House house3(1800, 2010);
    
    // Test equivalence function
    cout << "Equivalence test:" << endl;
    house1.print(); cout << " vs "; house2.print();
    cout << " : " << (equivalence(house1, house2) ? "Equivalent" : "Not equivalent") << endl;
    
    house1.print(); cout << " vs "; house3.print();
    cout << " : " << (equivalence(house1, house3) ? "Equivalent" : "Not equivalent") << endl;
    
    // Test compare function
    cout << "\nCompare function tests:" << endl;
    cout << "Small to large (true): ";
    house1.print(); cout << " <= "; house3.print();
    cout << " : " << (compare(house1, house3, true) ? "True" : "False") << endl;
    
    cout << "Large to small (false): ";
    house1.print(); cout << " >= "; house3.print();
    cout << " : " << (compare(house1, house3, false) ? "True" : "False") << endl;
    cout << endl;
}

// Test List operations
void testListOperations() {
    cout << "=== TESTING LIST OPERATIONS ===" << endl;
    
    List myList;
    
    // Test push_front
    cout << "Testing push_front..." << endl;
    myList.push_front(House(800, 1980));
    myList.push_front(House(600, 1970));
    cout << "After push_front: ";
    myList.print();
    
    // Test push_back
    cout << "Testing push_back..." << endl;
    myList.push_back(House(2000, 2015));
    myList.push_back(House(2500, 2020));
    cout << "After push_back: ";
    myList.print();
    
    // Test empty and front
    cout << "List empty: " << (myList.empty() ? "Yes" : "No") << endl;
    cout << "Front element: ";
    myList.front().print();
    cout << endl;
    
    // Test iterator
    cout << "Testing iterator traversal:" << endl;
    Iterator it = myList.begin();
    int count = 1;
    while (it.hasNext()) {
        cout << count << ". ";
        it.getData().print();
        it.next();
        count++;
    }
    cout << endl;
}

// Test find function
void testFindFunction() {
    cout << "=== TESTING FIND FUNCTION ===" << endl;
    
    List myList;
    myList.push_back(House(700, 1920));
    myList.push_back(House(900, 1940));
    myList.push_back(House(1200, 1950));
    
    cout << "List contents: ";
    myList.print();
    
    // Search for existing house
    House target1(900, 1940);
    Iterator result1 = myList.find(target1);
    if (result1.hasNext()) {
        cout << "Found: ";
        result1.getData().print();
    } else {
        cout << "House not found" << endl;
    }
    
    // Search for non-existing house
    House target2(1500, 2000);
    Iterator result2 = myList.find(target2);
    if (result2.hasNext()) {
        cout << "Found: ";
        result2.getData().print();
    } else {
        cout << "House (1500, 2000) not found" << endl;
    }
    cout << endl;
}

// Test CSV reading and complete list functionality
void testCSVAndCompleteList() {
    cout << "=== TESTING CSV READING AND COMPLETE LIST ===" << endl;
    
    List houses;
    
    // Read from CSV
    read(houses);
    cout << "After reading from data.csv: ";
    houses.print();
    cout << "List size should be 5 houses" << endl;
    cout << "List empty: " << (houses.empty() ? "Yes" : "No") << endl;
    
    // Test front element
    cout << "Front element: ";
    houses.front().print();
    cout << endl;
    
    // Test iterator with CSV data
    cout << "Iterating through CSV data:" << endl;
    Iterator it = houses.begin();
    int count = 1;
    while (it.hasNext()) {
        cout << count << ". ";
        it.getData().print();
        it.next();
        count++;
    }
    cout << endl;
}

// Test additional House operations on CSV data
void testHouseOperationsOnData() {
    cout << "=== TESTING HOUSE OPERATIONS ON CSV DATA ===" << endl;
    
    List houses;
    read(houses);
    
    // Test equivalence on actual data
    Iterator it = houses.begin();
    if (it.hasNext()) {
        House firstHouse = it.getData();
        cout << "First house: ";
        firstHouse.print();
        
        // Create a copy and test equivalence
        House copyHouse(firstHouse.getSize(), firstHouse.getYear());
        cout << "Copy house: ";
        copyHouse.print();
        cout << "Are they equivalent? " << (equivalence(firstHouse, copyHouse) ? "Yes" : "No") << endl;
        
        // Test compare function
        House largerHouse(3000, 2020);
        cout << "Compare " << firstHouse.getSize() << " <= " << largerHouse.getSize() 
             << " : " << (compare(firstHouse, largerHouse, true) ? "True" : "False") << endl;
    }
    cout << endl;
}



int main() {

    List houses;

    read(houses);
    houses.print();
     // Test 1: House class basic functionality
    testHouseClass();
    
    // Test 2: Utility functions (equivalence and compare)
    testUtilityFunctions();
    
    // Test 3: List operations with House objects
    testListOperations();
    
    // Test 4: Find function with House objects
    testFindFunction();
    
    // Test 5: CSV reading and complete list functionality
    testCSVAndCompleteList();
    
    // Test 6: Additional House operations on real data
    testHouseOperationsOnData();
    return 0;
}
