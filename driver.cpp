#include <iostream>
#include "LineKeeper.h"

int main(){
    LineKeeper lk = LineKeeper("input.txt");    
    lk.print(2);
    lk.print(11, 7);
}

