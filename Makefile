#Zhiyi Chen 11/11 Commit 1
# executable file to create and its dependancies
prog : driver.o Node.o Iterator.o List.o
g++ -std=c++11 -o prog driver.o Node.o Iterator.o List.o

# file dependencies
driver.o : List.h
g++ -std=c++11 -c driver.cpp
List.o : Node.h Iterator.h List.h
g++ -std=c++11 -c List.cpp
Iterator.o : Iterator.h
g++ -std=c++11 -c Iterator.cpp
Node.o : Node.h
g++ -std=c++11 -c Node.cpp

# files to remove
clean:
rm driver.o Node.o Iterator.o List.o
rm prog