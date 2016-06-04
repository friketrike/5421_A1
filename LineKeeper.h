/*
 * Assignennt 1, COMP 5421, summer 2016  
 * Federico O'Reilly Regueiro 40012304
 * Concordia University
 *
 * LineKeeper Class header
 */

#ifndef LINE_KEEPER
#define LINE_KEEPER

// uncomment to remove assert
// or better yet, handle via the makefile...
// #define NDEBUG

#include <cassert>
#include <cmath> // just so we can set width to cout
#include <iomanip> // this too...
#include <string>
#include <iostream>
#include <fstream>
#include "LinkedList.h"
#include "Line.h"

/**
 * LineKeeper Class. Contains a linked list of lines which gets
 * populated via a text file, the name of which must be supplied upon
 * construnction. *
 */
class LineKeeper {
  private:
    LinkedList<Line> list; /**< Linked list containing lines */

  public:
    LineKeeper()=delete;  // No default constructor here

    /**
     * Constructor, the only constructor.
     * @param filename the name of a text file from which lines will be pushed
     * into the line keeper's linked list
     */
    LineKeeper(const char * filename);

    /**
     * Default destructor
     */
    virtual ~LineKeeper()=default;


    /**
     * Print one or more lines between indices m and n.
     * If either of the indices are out of bounds, the intersection between the
     * range [m,n] and [1,line.size] will be taken.
     * @param m must be larger than 0 and less or equal to the amount of lines
     * the keeper keeps.
     * @param n has the sae constraints as m.
     */
    void print(int, int = 1);

  private:
    /**
     * Handles converting range defined by indices into a valid range.
     * @param m must be larger than 0 and less or equal to the amount of lines
     * the keeper keeps.
     * @param n has the sae constraints as m.
     */
    void setIndicesStraight(int &, int &);
};

#endif
