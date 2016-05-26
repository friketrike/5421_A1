#ifndef LINE_H
#define LINE_H
#include <iostream>
#include <cstring>
#include <cctype>
#include <stdexcept>

/**
 * The line class.
 * Holds a c-string line and knows its length and capacity.
 */
class Line{
  private:
    static const int DEFAULT_LINE_CAPACITY{50};/**<  Default length for a line.*/
    char * linePtr;         /**< pointer to the start of the c-string.*/
    int lineLength;         /**< number of characters stored. Terminator is not counted*/
    int lineCapacity;       /**< Amount of characters allocated in the array.*/

  public:
    // ctors
    Line();
    Line(const char*);
    Line(char);
    Line(const Line&);
    // dtor
    virtual ~Line();
    
    const Line & operator=(const Line& rhs);
    const char * cstr() const;
    int length() const;
    bool empty() const;
    bool full() const;
    int capacity() const;
    void resize(); // doubles capacity
    void push_back(const char&);
    void pop_back();
    friend std::ostream& operator<<(std::ostream& out, const Line& line);
    friend std::istream& operator>>(std::istream& in, Line& line); 

  private:
    static bool validChar(char); 
    void lineCpy(const char*);  
};

#endif
