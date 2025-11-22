//Zhiyi Chen 11/18 Commit#11
#include <iostream>
#include "List.h"                   //Gabriel Sencion 11/22 commit 15 adding read function
#include <fstream>
#include <sstream>
#include "House.h"

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




int main() {

    List houses;

    read(houses);
    houses.print();
    
    return 0;
}
