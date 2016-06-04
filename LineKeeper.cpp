/*
 * Assignennt 1, COMP 5421, summer 2016  
 * Federico O'Reilly Regueiro 40012304
 * Concordia University
 *
 * Implementation for the LineKeeper Class
 */

#include "LineKeeper.h"

// The assignment allows the C++ string class to be used outside of the Line
// So, we read the file via standard C++ strings and get c-strings from them
LineKeeper::LineKeeper(const char * filename):list{LinkedList<Line>()} {
    std::ifstream file(filename);
    std::string fileLine;
    if (file.is_open()) {
        while (getline(file, fileLine)) {
            list.push_back(Line(fileLine.c_str()));
        }
        file.close();
    }
    else { // give some form of minimal warning
        std::cerr << "Error: failed to open file" << filename << std::endl;
    }
}

void LineKeeper::print(int m, int n) { // remember n defaults to 1
    assert(list.size() > 0);
    setIndicesStraight(m, n);
    const int newWidth = std::floor(std::log10(n)+1);
    for (int i = m; i <= n; i++) {
        std::cout << "(" ;
        std::cout << std::setw(newWidth);
        std::cout << i;
        std::cout << ") ";
        list.print(i);
    } 
}

void LineKeeper::setIndicesStraight(int & m, int & n) { 
    bool valid = true;
     // you would think these could be avoided but we need to cache m and n...
    int start = m;
    int end = n;
    if (start > n) {
        int temp = start;
        start = end; 
        end = temp;
        valid = false;
    }
    if (start < 1) {
        start = 1;
        valid = false;
        // if end was also less than 1, set it to 1
        end = (end < 1) ? 1 : end;
    }
    if (end > list.size()) {
        end = list.size();
        valid = false;
        // if start was also larger than size, assign size to it
        start = (start > end) ? end : start;
    }
    if (valid == false) {
        std::cerr << "invalid range of line numbers from " 
            << m << " to " << n << std::endl;
        std::cerr << "default range from " << start << " to " 
            << end << " is now in effect." << std::endl;
    }
    m = start;
    n = end;
}
