#makefile for usenkok project 3

CXX = g++

# Compiler flags

CXXFLAGS = -std=gnu++11
#CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

project3: main.o game.o die.o character.o barbarian.o menuProj3.o medusa.o bluemen.o harrypotter.o vampire.o
	${CXX} ${CXXFLAGS} main.o game.o die.o character.o barbarian.o menuProj3.o medusa.o bluemen.o harrypotter.o vampire.o -o proj3

main.o: main.cpp
	${CXX} ${CXXFLAGS} -c main.cpp

menuProj3.o: menuProj3.cpp menuProj3.hpp
	${CXX} ${CXXFLAGS} -c menuProj3.cpp

game.o: game.cpp game.hpp
	${CXX} ${CXXFLAGS} -c game.cpp

die.o: die.cpp die.hpp
	${CXX} ${CXXFLAGS} -c die.cpp

character.o: character.cpp character.hpp
	${CXX} ${CXXFLAGS} -c character.cpp

barbarian.o: barbarian.cpp barbarian.hpp
	${CXX} ${CXXFLAGS} -c barbarian.cpp

medusa.o: medusa.cpp medusa.hpp
	${CXX} ${CXXFLAGS} -c medusa.cpp

bluemen.o: bluemen.cpp bluemen.hpp
	${CXX} ${CXXFLAGS} -c bluemen.cpp

harrypotter.o: harrypotter.cpp harrypotter.hpp
	${CXX} ${CXXFLAGS} -c harrypotter.cpp

vampire.o: vampire.cpp vampire.hpp
	${CXX} ${CXXFLAGS} -c vampire.cpp
clean:
	rm *.o
