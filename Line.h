#ifndef LINE_H
#define LINE_H
#include <iostream>
#include <cstring>
#include <cctype>
#include <stdexcept>

class Line{
  private:
    static const int DEFAULT_LINE_CAPACITY{50};
    char * linePtr;
    int lineLength;
    int lineCapacity;

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
    void push_back(const char& ch);
    void pop_back();
    friend std::ostream& operator<<(std::ostream& out, const Line& line);
    friend std::istream& operator>>(std::istream& in, Line& line); 

  private:
    static bool validChar(char); 
    void lineCpy(const char*);  
};

#endif
