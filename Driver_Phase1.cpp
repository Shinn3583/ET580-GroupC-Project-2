//Zhiyi Chen 11/11 Commit#1
#include <iostream>
#include "List.h"
//Gabriel adding main functions and updating driver file 11/14/25

int main() {
    List L;

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


    return 0;
}
