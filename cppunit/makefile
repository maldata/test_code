CXX=g++
CXXFLAGS=-Wall -std=c++11
LIBRARIES=-lcppunit
OBJECTFILES=complex.o complexfixture.o

%.o: %.cpp
	${CXX} ${CXXFLAGS} -c $<

main: main.cpp ${OBJECTFILES}
	${CXX} ${CXXFLAGS} -o $@ main.cpp ${OBJECTFILES} ${LIBRARIES}

clean:
	rm -f main
	rm -f *.o
	rm -f *~

PHONY: clean
