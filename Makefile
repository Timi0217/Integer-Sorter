CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -std=c++11
LDFLAGS  = -g3


sorter: sorter.o sortAlgs.o
	${CXX} ${LDFLAGS} ${CXXFLAGS} sorter.o sortAlgs.o -o sorter
	
testSortAlgs: testSortAlgs.o sortAlgs.o
	${CXX} ${LDFLAGS} ${CXXFLAGS} sortAlgs.o testSortAlgs.o -o testSortAlgs
	
sorter.o: sorter.cpp sortAlgs.h
	${CXX} ${LDFLAGS} ${CXXFLAGS} -c sorter.cpp
	
sortAlgs.o: sortAlgs.h sortAlgs.cpp 
	${CXX} ${LDFLAGS} ${CXXFLAGS} -c sortAlgs.cpp
	
testSortAlgs.o: testSortAlgs.cpp sortAlgs.h
	${CXX} ${LDFLAGS} ${CXXFLAGS} -c testSortAlgs.cpp
	
clean:
	rm sorter *.o 
	
cleanTests:
	rm testSortAlgs *.o
	
provide:
	provide comp15 hw5 sorter.cpp sortAlgs.cpp sortAlgs.h README Makefile \
	test.txt testSortAlgs.cpp

