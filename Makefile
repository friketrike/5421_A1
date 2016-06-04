# Makefile for assignennt 1, COMP 5421, summer 2016
# Federico O'Reilly Regueiro 40012304
# Concordia University
#
# This is based on the makefile tutorial that
# lives here http://mrbook.org/blog/tutorials/make/
#
CC=g++
CFLAGS=-c -Wall -std=c++11
CFLAGS_NO_D=-c -Wall -std=c++11 -D NDEBUG
LDFLAGS=

all: driver tester

driver: driver.o Line.o LineKeeper.o LinkedList.h
	$(CC) $(LDFLAGS) driver.o Line.o LineKeeper.o -o $@

driver.o: driver.cpp Line.cpp LineKeeper.cpp LinkedList.h
	$(CC) $(CFLAGS_NO_D) driver.cpp Line.cpp LineKeeper.cpp

tester: tester.o Line.o LineKeeper.o LinkedList.h
	$(CC) $(LDFLAGS) tester.o Line.o LineKeeper.o -o $@

tester.o: tester.cpp Line.cpp LineKeeper.cpp LinkedList.h
	$(CC) $(CFLAGS) tester.cpp Line.cpp LineKeeper.cpp

.PHONY: clean
clean:
	rm -f *.o *~ 

