/*
 * Assignennt 1, COMP 5421, summer 2016  
 * Federico O'Reilly Regueiro 40012304
 * Concordia University
 *
 * Line Class implementation file
 */
#include <cstddef> 
#include "Line.h"

// ctors
Line::Line():
  linePtr{new char[DEFAULT_LINE_CAPACITY+1]{}},
  lineLength{0},
  lineCapacity{DEFAULT_LINE_CAPACITY} {}

Line::Line(const char* ptr):
  linePtr{new char[std::strlen(ptr)+1]{}},
  lineLength{(int)std::strlen(ptr)},
  lineCapacity{(int)std::strlen(ptr)}
{
    lineCpy(ptr);
}

Line::Line(char c):
  linePtr{new char[DEFAULT_LINE_CAPACITY+1]{c, '\0'}},
  lineLength{(int)std::strlen(linePtr)}, // make it 0 if c == '\0'
  lineCapacity{DEFAULT_LINE_CAPACITY} {}

Line::Line(const Line& l):
  linePtr{new char[std::strlen(l.linePtr)+1]{}},
  lineLength{(int)std::strlen(l.linePtr)},
  lineCapacity{(int)std::strlen(l.linePtr)}
{
    lineCpy(l.linePtr);
}

Line::~Line(){
    delete[] linePtr;
}

const Line& Line::operator=(const Line& rhs){
    if(this != &rhs){ // avoid self-assignment
        delete [] linePtr;
        linePtr = new char[std::strlen(rhs.linePtr)+1]{};
        lineLength = std::strlen(rhs.linePtr);
        lineCapacity = std::strlen(rhs.linePtr);
        lineCpy(rhs.linePtr);
    }
    return *this;
}

const char* Line::cstr() const{
    return linePtr;
}

int Line::length() const{
    return lineLength;
}

bool Line::empty() const{
    return (strlen(linePtr) == 0);
}

bool Line::full() const{
    return (lineLength == lineCapacity);
}

int Line::capacity() const{
    return lineCapacity;
}

void Line::resize(){ // doubles capacity
    if (full()){
        char * temp{linePtr};
        int newCapacity = 
            (lineCapacity > 0) 
            ? 2*lineCapacity 
            : DEFAULT_LINE_CAPACITY;
        // this initializes all to '\0'
        linePtr = new char[(newCapacity)+1]{};
        lineCapacity = newCapacity;
        lineCpy(temp);
        delete [] temp;
    }
}

void Line::push_back(const char& ch){
    if (!validChar(ch)) return; // avoid inconsestencies from pushing invalid chars 
    /*if (full()){
        resize();
    } */
    resize();
    linePtr[lineLength]=ch;
    lineLength++;
    linePtr[lineLength]='\0';
}

void Line::pop_back(){
    if (empty()){
            std::string msg 
                = "error: popping an empty Line: index out of range";
            throw std::out_of_range(msg);
    }
    linePtr[lineLength-1]='\0';
    lineLength--;    
}   

// TODO write a back()

std::ostream& operator<<(std::ostream& out, const Line& line){
    char * temp = line.linePtr;
    while(Line::validChar(*temp)){
        out << *temp++;
    }
    out << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, Line& line){
    char * temp{line.linePtr+line.lineLength};
    char c;
    while(in >> std::noskipws >> c) {
        // detect end of line, have a special provision for windows 
        // line terminators (two characters)
        if (c == '\r'){
            if (std::cin.peek() == '\n'){
                in >> std::noskipws >> c; //consume for CR+LF terminator
            }
            break;
        }
        else if (c == '\n') {
            break;
        }
        // remove control characters just in case
        else if (!Line::validChar(c)) {
            continue;
        } // else

        // resize accordingly
        line.resize();
        temp = &line.linePtr[line.length()];
        /*if (line.full()) {
            std::ptrdiff_t offset{temp-line.linePtr};
            line.resize();
            temp = line.linePtr+offset;
        }*/
        *temp = c;
        temp++;
        line.lineLength++; 
    }
    temp='\0';
    return in;
} 

bool Line::validChar(char c) {
    return ((std::isprint(c) != 0) 
            || (std::isblank(c) != 0));
}

void Line::lineCpy(const char * ptr){
    strcpy(linePtr, ptr);
}

