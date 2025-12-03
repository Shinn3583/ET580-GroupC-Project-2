# Zhiyi Chen 11/11 Commit 1
# Gabriel fixing MakeFile errors 11/14/25
# Zhiyi Chen 11/18 update makefile
# Sikder Ishaq comments added 11/28
# Zhiyi Chen 11/29 fixed makefile
# executable file to create and its dependencies
prog3: driver_phase3.o Node.o Iterator.o List.o House.o
	 g++ -std=c++11 -o prog3 Node.o Iterator.o List.o House.o driver_phase3.o

# file dependencies
driver_phase1.o: driver_phase1.cpp List.h Node.h Iterator.h
	 g++ -std=c++11 -c driver_phase1.cpp

List.o: List.cpp Node.h Iterator.h List.h
	 g++ -std=c++11 -c List.cpp

Iterator.o: Iterator.cpp Iterator.h
	 g++ -std=c++11 -c Iterator.cpp

Node.o: Node.cpp Node.h
	 g++ -std=c++11 -c Node.cpp

driver_phase2.o: driver_phase2.cpp List.h Node.h Iterator.h House.h
	 g++ -std=c++11 -c driver_phase2.cpp

driver_phase3.o: driver_phase3.cpp List.h Node.h Iterator.h House.h
	 g++ -std=c++11 -c driver_phase3.cpp

House.o: House.cpp House.h
	 g++ -std=c++11 -c House.cpp

# files to remove
clean:
	 rm -f Node.o Iterator.o List.o driver_phase3.o House.o
	 rm -f prog3
