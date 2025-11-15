#Zhiyi Chen 11/11 Commit 1
# executable file to create and its dependancies
#Gabriel fixing MakeFile errors (improper syntax and file names for driver) 11/14/25
prog : driver.o Node.o Iterator.o List.o
	g++ -std=c++11 -o prog Driver_Phase1.o Node.o Iterator.o List.o

# file dependencies
driver.o : List.h
	g++ -std=c++11 -c Driver_Phase1.cpp

List.o : Node.h Iterator.h List.h
	g++ -std=c++11 -c List.cpp

Iterator.o : Iterator.h
	g++ -std=c++11 -c Iterator.cpp

Node.o : Node.h
	g++ -std=c++11 -c Node.cpp

# files to remove
clean:
	rm Driver_Phase1.o Node.o Iterator.o List.o
	rm prog 