/*
 * Assignennt 1, COMP 5421, summer 2016  
 * Federico O'Reilly Regueiro 40012304
 * Concordia University
 *
 * Line Class header file
 */
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
    static const int DEFAULT_LINE_CAPACITY{50};/**< Default length for a line.*/
    char * linePtr;       /**< pointer to the start of the c-string.*/
    int lineLength;       /**< number of chars stored. '\0' is not counted*/
    int lineCapacity;     /**< Amount of characters allocated in the array.*/

  public:
    // ctors
    /**
     *Default constructor.
     */
    Line();

    /**
     * Constructor with c-string.
     * Takes a c-string to construct a line object. The Line's length is
     * set to the input string's length.
     * @param ptr points to the start of the input c-string. 
     */
    Line(const char*);

    /**
     * Minimal constructor.
     * Takes one character to construct a line.
     * @param c is a character to start off a Line object.
     */
    Line(char);

    /**
     * Copy constructor.
     * Given a reference to a Line object, construct a (deep) copy.
     * @param l is a reference to an existing line object to be deep-copied.
     */
    Line(const Line&);
   
    /**
     * default virtual destructor
     */
    virtual ~Line();
    
    /**
     * Assignment operator.
     * Given an existing Line object, deep-copy into *this
     * @param rhs existing Line obj to be deep-copied into *this
     */
    const Line & operator=(const Line& rhs);

    /**
     * Return a c-string version of this line.
     */
    const char * cstr() const;

    /**
     * Returns the length, in chars, of this Line object
     */
    int length() const;

    /**
     * Returns true if the line contains no characters.
     */
    bool empty() const;

    /**
     * True if the Line size equals its capacity.
     */
    bool full() const;

    /**
     * Return the size, in chars, of the Line's allocated memory.
     * Does not include the space for a null-terminator
     */
    int capacity() const;

    /**
     * Double capacity if the line is full
     */
    void resize(); // doubles capacity

    /**
     * Append a character to the line.
     * Calling this method on a full line will automatically resize it
     * @param ch is a reference to the character to be appended
     */
    void push_back(const char&);

    /**
     * Remove the last character from the Line
     */
    void pop_back();

    /**
     * Insertion operator.
     * Streamlining ;).
     * Performs some sanity checks on input, character by character, accepting
     * only print characters and space characters.
     * @param out returns a reference to the output stream.
     * @param line is a reference to the Line object to be inserted.
     */
    friend std::ostream& operator<<(std::ostream& out, const Line& line);
    
    /**
     * Extraction operator.
     * Performs some sanity checks on input, character by character, accepting
     * only print characters and space characters.
     * @param in returns a reference to the input stream.
     * @param line is a reference to the extracting Line object.
     */
    friend std::istream& operator>>(std::istream& in, Line& line); 

  private:
    /**
     * Helper function for extraction and insertion operators.
     * Evaluate that the character is a print or space character.
     * @param c is the value of the character to be evaluated.
     */ 
    static bool validChar(char); 

    /**
     * Copy the string into *this.lineptr.
     * @param ptr is a pointer to the c-string to be copied into this line. 
     */
    void lineCpy(const char*);  
};

#endif
