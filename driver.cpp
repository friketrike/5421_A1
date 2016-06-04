/*
 * Assignennt 1, COMP 5421, summer 2016  
 * Federico O'Reilly Regueiro 40012304
 * Concordia University
 *
 * Small driver for the LineKeeper Class
 */

#include <iostream>
#include "LineKeeper.h"

int main(){
    LineKeeper lk = LineKeeper("input.txt");    
    lk.print(2);
    lk.print(11, 7);
    lk.print(-3, -4);
    lk.print(80, 130);
    lk.print(26,1);
}

