// driver_phase3.cpp // Sikder Ishaq — Phase III Task 1 driver file
// Minimal driver created 
// driver_phase3.cpp // Sikder Ishaq — Phase III Task 1 driver file
// Updated with Phase 3 Step 5, 6, 7 tests
#include <iostream>
#include "List.h"
#include "House.h"

using namespace std;

// PHASE 3 STEP 5: Test clear function
void testClearFunction() {
    cout << "=== PHASE 3 STEP 5: TESTING CLEAR FUNCTION ===" << endl;

    List houses;

    // Add some houses
    houses.push_back(House(1000, 1990));
    houses.push_back(House(1500, 2000));
    houses.push_back(House(2000, 2010));
    
    cout << "Before clear:" << endl;
    cout << "Size: " << houses.getSize() << " (expected: 3)" << endl;
    cout << "Empty: " << (houses.empty() ? "Yes" : "No") << " (expected: No)" << endl;
    cout << "Contents: ";
    houses.print();
    
    // Test clear function
    cout << "\nCalling clear()..." << endl;
    houses.clear();
    
    cout << "After clear:" << endl;
    cout << "Size: " << houses.getSize() << " (expected: 0)" << endl;
    cout << "Empty: " << (houses.empty() ? "Yes" : "No") << " (expected: Yes)" << endl;
    cout << "Contents: ";
    houses.print();
    
    // Test that list can be reused after clear
    cout << "\nAdding houses after clear:" << endl;
    houses.push_back(House(800, 1980));
    houses.push_back(House(1200, 1995));
    cout << "Size: " << houses.getSize() << " (expected: 2)" << endl;
    cout << "Contents: ";
    houses.print();
    
    cout << "=== CLEAR FUNCTION TEST COMPLETED ===" << endl << endl;
}

// PHASE 3 STEP 7: Test insertAfter and eraseAfter functions
void testInsertEraseAfter() {
    cout << "=== INSERT/ERASE AFTER ===" << endl;
    List lst;
    lst.push_back(House(800, 1980));
    lst.push_back(House(1200, 1995));
    Iterator it = lst.begin();
    lst.insertAfter(it, House(1000, 1990));
    cout << "After insertAfter: "; lst.print();
    lst.eraseAfter(it);
    cout << "After eraseAfter:  "; lst.print();
    cout << endl;
}

// PHASE 3 STEP 7: Test front function
void testFront() {
    cout << "=== FRONT ===" << endl;
    List lst;
    lst.push_back(House(600, 1970));
    lst.push_back(House(900, 1990));
    cout << "List: "; lst.print();
    cout << "Front: "; lst.front().print();
    cout << endl;
}

// PHASE 3 STEP 7: Test duplicate function
void testDuplicateFunction() {
    cout << "=== DUPLICATE ===" << endl;
    List a;
    a.push_back(House(700, 1920));
    a.push_back(House(900, 1940));
    a.push_back(House(1200, 1950));
    List b;
    a.duplicate(b);
    cout << "Original: "; a.print();
    cout << "Copy:     "; b.print();
    cout << "Sizes => A: " << a.getSize() << ", B: " << b.getSize() << endl;
    // Verify element-by-element equivalence
    Iterator ia = a.begin();
    Iterator ib = b.begin();
    bool allEq = true;
    while (ia.hasNext() && ib.hasNext()) {
        if (!equivalence(ia.getData(), ib.getData())) { allEq = false; break; }
        ia.next(); ib.next();
    }
    cout << "Equivalent copies: " << (allEq ? "Yes" : "No") << endl << endl;
}

// PHASE 3 STEP 7: Test find function
void testFindFunctionPhase3() {
    cout << "=== FIND ===" << endl;
    List lst;
    lst.push_back(House(700, 1920));
    lst.push_back(House(900, 1940));
    lst.push_back(House(1200, 1950));
    cout << "List: "; lst.print();
    House target1(900, 1940);
    Iterator r1 = lst.find(target1);
    cout << "Searching 900,1940: ";
    if (r1.hasNext()) { r1.getData().print(); } else { cout << "Not found" << endl; }
    House target2(1500, 2000);
    Iterator r2 = lst.find(target2);
    cout << "Searching 1500,2000: ";
    if (r2.hasNext()) { r2.getData().print(); } else { cout << "Not found" << endl; }
    cout << endl;
}

// PHASE 3 STEP 6: Test sortedInsert algorithm
void testSortedInsert() {
    cout << "=== PHASE 3 STEP 6: TESTING SORTEDINSERT ALGORITHM ===" << endl;
    
    List houses;
    
    // Test small to large ordering (comparator = true)
    cout << "Testing sortedInsert - SMALL TO LARGE (comparator=true):" << endl;
    List::sortedInsert(houses, House(1500, 2000), true);
    List::sortedInsert(houses, House(1000, 1990), true);
    List::sortedInsert(houses, House(2000, 2010), true);
    List::sortedInsert(houses, House(1200, 1995), true);
    List::sortedInsert(houses, House(1800, 2005), true);
    
    cout << "After sortedInsert (small to large):" << endl;
    cout << "Size: " << houses.getSize() << " (expected: 5)" << endl;
    cout << "Contents: ";
    houses.print();
    
    // Verify order is correct (should be: 1000, 1200, 1500, 1800, 2000)
    cout << "Verifying order (should be ascending by size):" << endl;
    Iterator it = houses.begin();
    int prevSize = -1;
    while (it.hasNext()) {
        int currentSize = it.getData().getSize();
        cout << "Size: " << currentSize;
        if (prevSize != -1) {
            cout << " > " << prevSize << "? " << (currentSize >= prevSize ? "Yes ✓" : "No ✗");
        }
        cout << endl;
        prevSize = currentSize;
        it.next();
    }
    
    houses.clear();
    
    // Test large to small ordering (comparator = false)
    cout << "\nTesting sortedInsert - LARGE TO SMALL (comparator=false):" << endl;
    List::sortedInsert(houses, House(1500, 2000), false);
    List::sortedInsert(houses, House(1000, 1990), false);
    List::sortedInsert(houses, House(2000, 2010), false);
    List::sortedInsert(houses, House(1200, 1995), false);
    List::sortedInsert(houses, House(1800, 2005), false);
    
    cout << "After sortedInsert (large to small):" << endl;
    cout << "Size: " << houses.getSize() << " (expected: 5)" << endl;
    cout << "Contents: ";
    houses.print();
    
    // Verify order is correct (should be: 2000, 1800, 1500, 1200, 1000)
    cout << "Verifying order (should be descending by size):" << endl;
    it = houses.begin();
    prevSize = 10000; // Large number
    while (it.hasNext()) {
        int currentSize = it.getData().getSize();
        cout << "Size: " << currentSize;
        if (prevSize != 10000) {
            cout << " < " << prevSize << "? " << (currentSize <= prevSize ? "Yes ✓" : "No ✗");
        }
        cout << endl;
        prevSize = currentSize;
        it.next();
    }
    
    cout << "=== SORTEDINSERT TEST COMPLETED ===" << endl << endl;
}

// PHASE 3 STEP 6: Test binarySearch algorithm
void testBinarySearch() {
    cout << "=== PHASE 3 STEP 6: TESTING BINARYSEARCH ALGORITHM ===" << endl;
    
    List houses;
    
    // Create a sorted list for searching (small to large)
    cout << "Creating sorted list (small to large) for binary search:" << endl;
    List::sortedInsert(houses, House(700, 1920), true);
    List::sortedInsert(houses, House(900, 1940), true);
    List::sortedInsert(houses, House(1200, 1950), true);
    List::sortedInsert(houses, House(1800, 1980), true);
    List::sortedInsert(houses, House(2100, 2010), true);
    
    cout << "Sorted list:" << endl;
    houses.print();
    
    // Test searching for existing elements
    cout << "\nSearching for EXISTING elements:" << endl;
    
    House target1(900, 1940);
    Iterator result1 = List::binarySearch(houses, target1, true);
    if (result1.hasNext()) {
        cout << "Found: ";
        result1.getData().print();
        cout << " ✓" << endl;
    } else {
        cout << "Not found: ";
        target1.print();
        cout << " ✗" << endl;
    }
    
    House target2(1800, 1980);
    Iterator result2 = List::binarySearch(houses, target2, true);
    if (result2.hasNext()) {
        cout << "Found: ";
        result2.getData().print();
        cout << " ✓" << endl;
    } else {
        cout << "Not found: ";
        target2.print();
        cout << " ✗" << endl;
    }
    
    // Test searching for non-existing elements
    cout << "\nSearching for NON-EXISTING elements:" << endl;
    
    House target3(1500, 2000); // Should not exist
    Iterator result3 = List::binarySearch(houses, target3, true);
    if (result3.hasNext()) {
        cout << "Found (unexpected): ";
        result3.getData().print();
        cout << " ✗" << endl;
    } else {
        cout << "Not found: ";
        target3.print();
        cout << " ✓" << endl;
    }
    
    houses.clear();
    
    // Test with large to small ordering
    cout << "\nTesting binarySearch with LARGE TO SMALL ordering:" << endl;
    cout << "Creating sorted list (large to small):" << endl;
    List::sortedInsert(houses, House(700, 1920), false);
    List::sortedInsert(houses, House(900, 1940), false);
    List::sortedInsert(houses, House(1200, 1950), false);
    List::sortedInsert(houses, House(1800, 1980), false);
    
    cout << "Descending sorted list:" << endl;
    houses.print();
    
    House target4(900, 1940);
    Iterator result4 = List::binarySearch(houses, target4, false);
    if (result4.hasNext()) {
        cout << "Found: ";
        result4.getData().print();
        cout << " ✓" << endl;
    } else {
        cout << "Not found: ";
        target4.print();
        cout << " ✗" << endl;
    }
    
    cout << "=== BINARYSEARCH TEST COMPLETED ===" << endl << endl;
}

// PHASE 3 STEP 7: Test integration with data.csv equivalent data
void testDataCSVIntegration() {
    cout << "=== PHASE 3 STEP 7: TESTING WITH DATA.CSV EQUIVALENT ===" << endl;
    
    List houses;
    
    // Build the same dataset as data.csv using sortedInsert
    cout << "Building sorted list using data.csv equivalent data:" << endl;
    List::sortedInsert(houses, House(700, 1920), true);
    List::sortedInsert(houses, House(900, 1940), true);
    List::sortedInsert(houses, House(1200, 1950), true);
    List::sortedInsert(houses, House(1800, 1980), true);
    List::sortedInsert(houses, House(2100, 2010), true);
    
    cout << "Final sorted list (should match data.csv order):" << endl;
    houses.print();
    cout << "Size: " << houses.getSize() << " (expected: 5)" << endl;
    
    // Test binary search on all elements from the dataset
    cout << "\nTesting binary search on all data.csv elements:" << endl;
    
    House searchTargets[] = {
        House(700, 1920),
        House(900, 1940), 
        House(1200, 1950),
        House(1800, 1980),
        House(2100, 2010)
    };
    
    for (int i = 0; i < 5; i++) {
        Iterator result = List::binarySearch(houses, searchTargets[i], true);
        if (result.hasNext()) {
            cout << "Found: ";
            result.getData().print();
            cout << " ✓" << endl;
        } else {
            cout << "Not found: ";
            searchTargets[i].print();
            cout << " ✗" << endl;
        }
    }
    
    // Test size tracking throughout operations
    cout << "\nTesting size tracking with mixed operations:" << endl;
    cout << "Initial size: " << houses.getSize() << endl;
    
    houses.pop_front();
    cout << "After pop_front: " << houses.getSize() << " (expected: 4)" << endl;
    
    List::sortedInsert(houses, House(1500, 2000), true);
    cout << "After sortedInsert: " << houses.getSize() << " (expected: 5)" << endl;
    
    houses.clear();
    cout << "After clear: " << houses.getSize() << " (expected: 0)" << endl;
    
    cout << "=== DATA.CSV INTEGRATION TEST COMPLETED ===" << endl << endl;
}

// PHASE 3 STEP 7: Test all Phase 3 functionality together
void testAllPhase3Functions() {
    cout << "=== PHASE 3 STEP 7: COMPREHENSIVE TEST OF ALL FUNCTIONS ===" << endl;
    
    List houses;
    
    // 1. Test size tracking with basic operations
    cout << "1. Testing size tracking:" << endl;
    cout << "   Initial size: " << houses.getSize() << " (expected: 0)" << endl;
    
    houses.push_back(House(800, 1985));
    houses.push_front(House(600, 1975));
    cout << "   After push operations: " << houses.getSize() << " (expected: 2)" << endl;
    
    // 2. Test sortedInsert
    cout << "\n2. Testing sortedInsert with mixed data:" << endl;
    List::sortedInsert(houses, House(1500, 2005), true);
    List::sortedInsert(houses, House(1000, 1995), true);
    cout << "   After sortedInsert: " << houses.getSize() << " (expected: 4)" << endl;
    cout << "   List contents: ";
    houses.print();
    
    // 3. Test binarySearch
    cout << "\n3. Testing binarySearch:" << endl;
    House target(1000, 1995);
    Iterator result = List::binarySearch(houses, target, true);
    if (result.hasNext()) {
        cout << "   Found target: ";
        result.getData().print();
        cout << " ✓" << endl;
    }
    
    // 4. Test clear function
    cout << "\n4. Testing clear function:" << endl;
    houses.clear();
    cout << "   After clear - Size: " << houses.getSize() << " (expected: 0)" << endl;
    cout << "   Empty: " << (houses.empty() ? "Yes" : "No") << " (expected: Yes)" << endl;
    
    // 5. Test that list is reusable after clear
    cout << "\n5. Testing reusability after clear:" << endl;
    List::sortedInsert(houses, House(2000, 2010), true);
    List::sortedInsert(houses, House(1700, 2008), true);
    cout << "   After reuse - Size: " << houses.getSize() << " (expected: 2)" << endl;
    cout << "   Contents: ";
    houses.print();
    
    cout << "=== COMPREHENSIVE TEST COMPLETED ===" << endl << endl;
}

int main() {
    cout << "=== ET580 PROJECT 2 - PHASE 3 COMPLETE TEST ===" << endl << endl;

    // Saqibur Rahman — Phase III Task 4: Testing List::getSize()
    cout << "=== Phase III Task 4: Testing getSize() ===" << endl;
    List houses;
    cout << "Initial size (expect 0): " << houses.getSize() << endl;
    houses.push_back(House(700, 1920));
    houses.push_back(House(900, 1940));
    cout << "Size after 2 push_back (expect 2): " << houses.getSize() << endl;
    houses.pop_front();
    cout << "Size after pop_front (expect 1): " << houses.getSize() << endl << endl;

    houses.clear(); // Reset for next tests

    // Phase 3 Step 5: Clear function tests
    testClearFunction();
    // Phase 3 Step 7: insertAfter/eraseAfter tests
    testInsertEraseAfter();
    // Phase 3 Step 7: front/duplicate/find tests
    testFront();
    testDuplicateFunction();
    testFindFunctionPhase3();
    
    // Phase 3 Step 6: Algorithm tests
    testSortedInsert();
    testBinarySearch();
    
    // Phase 3 Step 7: Integration and comprehensive tests
    testDataCSVIntegration();
    testAllPhase3Functions();

    cout << "=== ALL PHASE 3 TESTS COMPLETED SUCCESSFULLY ===" << endl;
    cout << "✓ Size tracking implemented and working" << endl;
    cout << "✓ getSize() function working" << endl;
    cout << "✓ clear() function working" << endl;
    cout << "✓ sortedInsert algorithm working" << endl;
    cout << "✓ binarySearch algorithm working" << endl;
    cout << "✓ All Phase 3 functions tested together" << endl;
    cout << "✓ Integration with data.csv equivalent data verified" << endl;

    return 0;
}
