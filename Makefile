#Zhiyi Chen 11/11 Commit 1
# executable file to create and its dependancies
#Gabriel fixing MakeFile errors (improper syntax and file names for driver) 11/14/25
#Gabriel fixing Makefile again syntax
#Zhiyi Chen 11/18 Commit 11
#Zhiyi Chen 11/18 update makefile 
#Sikder Ishaq — comments added 11/28: Phase 3 driver target and clean rules
prog : Driver_Phase2.o Node.o Iterator.o List.o House.o
    g++ -std=c++11 -o prog Driver_Phase2.o Node.o Iterator.o List.o House.o

# file dependencies
Driver_Phase2.o : List.h Iterator.h Node.h 
    g++ -std=c++11 -c Driver_Phase2.cpp

Driver_Phase3.o : List.h Iterator.h Node.h 
    g++ -std=c++11 -c Driver_Phase3.cpp

Driver_Phase1.o : List.h Iterator.h Node.h 
    g++ -std=c++11 -c Driver_Phase1.cpp
        
prog1 : Driver_Phase1.o Node.o Iterator.o List.o House.o
    g++ -std=c++11 -o prog1 Driver_Phase1.o Node.o Iterator.o List.o House.o

prog3 : Driver_Phase3.o Node.o Iterator.o List.o House.o
    g++ -std=c++11 -o prog3 Driver_Phase3.o Node.o Iterator.o List.o House.o

List.o : Node.h Iterator.h List.h
	g++ -std=c++11 -c List.cpp

Iterator.o : Iterator.h Node.h
	g++ -std=c++11 -c Iterator.cpp

Node.o : Node.h
	g++ -std=c++11 -c Node.cpp

House.o : House.h 
	g++ -std=c++11 -c House.cpp 

# files to remove
clean:
    rm -f Driver_Phase1.o Driver_Phase2.o Driver_Phase3.o Node.o Iterator.o List.o House.o
    rm -f prog prog1 prog3
