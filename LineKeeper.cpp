#include "LineKeeper.h"

LineKeeper::LineKeeper(const char * filename):list{LinkedList<Line>()} {
    std::ifstream file(filename);
    std::string fileLine;
    if (file.is_open()) {// TODO give meaningful error info
        while (getline(file, fileLine)) {
            list.push_back(Line(fileLine.c_str()));
        }
        file.close();
    }
}

void LineKeeper::print(int m){
    print(m, m);
}

void LineKeeper::print(int m, int n){
    if (list.size() == 0) {
        std::cerr  << "Warning, trying to print an empty line" << std::endl;
        return;
    }
    setIndicesStraight(m, n);
    for (int i = m; i <= n; i++) {
        list.print(i);
    } 
}

void LineKeeper::setIndicesStraight(int & m, int & n){
    bool valid = true;
    int start = m;
    int end = n;
    if (start > end) {
        int temp = start;
        start = end; 
        end = temp;
        valid = false;
    }
    if (start < 1) {
        start = 1;
        valid = false;
    }
    if (end > list.size()) {
        end = list.size();
        valid = false;
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
