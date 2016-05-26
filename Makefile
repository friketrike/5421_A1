# Makefile for assignennt 1, COMP 5421, summer 2016
# Federico O'Reilly Regueiro 40012304
# Concordia University
#
# This is a modification to one of the makefiles from the makefile tutorial that
# lives here http://mrbook.org/blog/tutorials/make/
#
CC=g++
CFLAGS=-c -Wall -std=c++11
LDFLAGS=
SOURCES=Line.cpp LineKeeper.cpp driver.cpp
# LinkedList is not in te sources list since being a template requires it to
# either be declared in the header or the source to be included in .h
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=driver

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f *.o *~ 
