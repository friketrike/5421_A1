#ifndef LINE_KEEPER
#define LINE_KEEPER

#include <string>
//#include <iostream>
#include <fstream>
#include "LinkedList.h"
#include "Line.h"

class LineKeeper {
  private:
    LinkedList<Line> list;

  public:
    LineKeeper(const char *);

    void print(int);

    void print(int, int);

  private:
    void setIndicesStraight(int &, int &);
};

#endif
