#include <iostream>
#include "Line.h"
#include "LinkedList.h"

int main(){
    // First test the line class to a certain extent
    Line l1;
    Line l2{"Two"};
    Line l3 = l2; // l3(l2) works too
    Line l4(" ");

    Line * lp = new Line();
    std::cin >> l1; //TODO what about chaining two line objects?
    l4 = l2;
    int l4Length = l4.length();
    for(int i = 0; i < l4Length; i++){
        l4.pop_back();
    }
    //l4.push_back(' ');
    l4.push_back('F');
    l4.push_back('\0');//shouldn't get pushed in
    l4.push_back('o');
    l4.push_back('u');
    l4.push_back('r');

    std::cout << "Line pointer with default ctor has size " 
        << lp->length() << " capacity: " << lp->capacity() 
        << " and it is: \"" << *lp << "\"" << std::endl;
    std::cout << "L1 with default ctor  and cin has size " 
        << l1.length() <<  " capacity: " << l1.capacity() 
        << " and it is: \"" << l1 << "\"" << std::endl;    
    std::cout << "L2 with const char * ctor has size " 
        << l2.length() << " capacity: " << l2.capacity() 
        << " and it is: \"" << l2 << "\"" << std::endl; 
    std::cout << "L3 with copy ctor from l2 has size " 
        << l3.length() << " capacity: " << l3.capacity() 
        << " and it is: \"" << l3 << "\"" << std::endl;
    std::cout << "L4 size 1  and operator=(l2)/pop/push has size " 
        << l4.length() << " capacity: " << l4.capacity() 
        << " and it is: \"" << l4 << "\"" << std::endl;
    delete lp;
    l3 = Line("Three");

    std::cout << "The lines, in order, are: " << std::endl
        << l1 << l2 << l3 << l4 << std::endl;
    
    // Now test LinkedList
    LinkedList<Line> *llp1;
    llp1 = new LinkedList<Line>();
    std::cout << "l-list generated with argument-les constructor is " 
        << llp1->size() << " nodes" << std::endl;    
    llp1->push_back(Line("Three"));
    std::cout << "l-list is " << llp1->size() << " nodes" << std::endl;    
    llp1->push_back(l4);
    llp1->push_front(Line("Two"));
    llp1->push_front(l1);
    
    std::cout << "the list is " << llp1->size() << "after pushing. "
        << "The first element is: ";
    llp1->print(1); 
    std::cout << ", and the last one is: ";
    llp1->print(4); 
    
    for (int i = 0; i < 4; i++) {
        llp1->print(i+1);
    } 
    /* Both fail like they should:
     * llp1->print(0);
     * llp1->print(5); */

    //copy ctor
    LinkedList<Line> * llp2 = new LinkedList<Line>(*llp1);
    std::cout << std::endl;
    std::cout << "llp2 from copy constructor is: " 
        << llp2->size() << " nodes and contains: " << std::endl;
    for (int i = 0; i < 4; i++) {
        llp2->print(i+1);
    }  
    
    int  llp1Length = llp1->size(); 
    for (int i = 0; i <  llp1Length; i++) {
        //llp1->pop_front();
        llp1->pop_back();
    }
    // llp1->pop_front(); // Should fail
    // llp1->pop_back(); // Should fail

    //copy ctor from empty list
    LinkedList<Line> * llp3 = new LinkedList<Line>(*llp1); 
  
    // llp3->insert(Line("wrong"), 2);
    llp3->insert(Line("right"), 1);

    LinkedList<Line> * llp4 = new LinkedList<Line>(*llp2);
    
    // assignment operator cases
    llp4 = llp3; // smaller list onto larger list
       
    std::cout << std::endl;
    std::cout << "llp4 from operator= with a one element list is: " 
        << llp4->size() << " nodes and contains: " << std::endl;
    
    int  llp4Length = llp4->size(); 
    for (int i = 0; i <  llp4Length; i++) {
        llp4->print(i+1);
    }
    

    llp4 = llp1; // empty list onto larger list   
    std::cout << std::endl;
    std::cout << "llp4 from operator= with an empty list is: " 
        << llp4->size() << " nodes and contains: " << std::endl;    
    std::cout << "The list is empty: "<< llp4->empty() << std::endl;

    llp4Length = llp4->size(); 
    for (int i = 0; i <  llp4Length; i++) {
        llp4->print(i+1);
    }
    
    llp4 = llp2; // larger list onto smaller list   
    std::cout << std::endl;
    std::cout << "llp4 from operator= with an empty list is: " 
        << llp4->size() << " nodes and contains: " << std::endl;
    std::cout << "The list is empty: "<< llp4->empty() << std::endl;

    llp4Length = llp4->size(); 
    for (int i = 0; i <  llp4Length; i++) {
        llp4->print(i+1);
    }
    
    // removal
    // llp4->remove(5); // fails
    llp4->remove(4);
    std::cout << "the list should now have 3 nodes, it has: " 
        << llp4->size() << std::endl;
    
    // bye bye
    delete llp1;
    delete llp2;
    delete llp3;
    delete llp4;
}
