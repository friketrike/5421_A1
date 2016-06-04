/*
 * Assignennt 1, COMP 5421, summer 2016  
 * Federico O'Reilly Regueiro 40012304
 * Concordia University
 *
 * Testing class for the Line / LinkedList / LineKeeper Classes
 */

#include <iostream>
#include <string>
#include "Line.h"
#include "LinkedList.h"

int main(){
    // Some methods for printing meaningful info
    struct D {
        static void printDebugInfo(Line & l, 
                const std::string mesg = ""){
            std::cout << "Line " << mesg << std::endl 
                << " address: " << &l << std::endl
                << " length: " << l.length() << std::endl
                <<" capacity: " << l.capacity() << std::endl
                << " contents: " << l;
        }

        static void printDebugInfo(LinkedList<Line>::ListNode & n, 
                const int idx){
            std::cout << "****node " << idx << "****" << std::endl 
                << " address: " << &n << std::endl
                << " prev points to: " << n.prev << std::endl
                <<" next point to: " << n.next << std::endl
                << " contents: " << n.data;
        }

        static void printDebugInfo(LinkedList<Line> & ll, 
                const std::string mesg = "" ) { 
            std::cout << "LinkedList " << mesg << std::endl 
                << " address: " << &ll << std::endl
                << " length: " << ll.size() << std::endl
                << " empty?: " << ll.empty() << std::endl
                << " contents: " << std::endl;
            LinkedList<Line>::ListNode * p = ll.head;
            // size + 2 for head and tail
            for (int i = 0; i < ll.size() + 2; ++i) {
                printDebugInfo(*p, i);
                p = p->next;
            }
        }
    };
    // First test the line class to a certain extent
    Line l1;
    Line l2{"Two"};
    Line l3 = l2; // l3(l2) works too
    Line l4('c');
    Line l5('\0');

    Line * lp = new Line();
    std::cout << "Enter a line: (entering \"One\" works nicely)" 
        << std::endl;
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

    // print info about each line after constructing
    D::printDebugInfo(*lp, "from line ptr with default ctor.");
    D::printDebugInfo(l1, "l1 with default ctor and operator>>. ");
    D::printDebugInfo(l2,  "l2 with const char * ctor." );
    D::printDebugInfo(l3, "l3, copy ctor from l2.");
    D::printDebugInfo(l4, "l4, 1 char constructor and 1 pop, 4 pushes");
    D::printDebugInfo(l5, "l5, 1 char constructor using '\\0'");
    delete lp;
    l3 = Line("Three");
    // verify that concatenated insertion operators
    std::cout << "The lines, in order, are: " << std::endl
        << l1 << l2 << l3 << l4 << std::endl;
    
    // Now test LinkedList
    LinkedList<Line> ll1;
    std::cout << "l-list generated with default ctor is " 
        << ll1.size() << " nodes" << std::endl;    
    D::printDebugInfo(ll1, "l-list generated with default ctor "); 

    ll1.push_back(Line("Three"));
    
    D::printDebugInfo(l1,
            "after pushing \"Three\" ");
    ll1.push_back(l4);
    ll1.push_front(Line("Two"));
    ll1.push_front(l1);
    
    // now call the print function to make sure it works
    std::cout << "the list is " << ll1.size() << "after pushing. "
        << "The first element is: ";
    ll1.print(1); 
    std::cout << ", and the last one is: ";
    ll1.print(4);     
    /* Both fail like they should:
     * ll1.print(0);
     * ll1.print(5); */

    D::printDebugInfo(ll1, "Now ll1 looks like this: ");
    //copy ctor
    LinkedList<Line> * llp2 = new LinkedList<Line>(ll1);
    D::printDebugInfo(*llp2, "llp2 from copy ctor. "); 
    
    // now pop everything
    int  llp1Length = ll1.size(); 
    for (int i = 0; i <  llp1Length; i++) {
        //ll1.pop_front();
        ll1.pop_back();
    }
    // ll1.pop_front(); // Should fail
    // ll1.pop_back(); // Should fail

    //copy ctor from empty list
    LinkedList<Line> ll3(ll1); 
  
    // llp3.insert(Line("wrong"), 2);
    ll3.insert(Line("right"), 1);

    LinkedList<Line> * llp4 = new LinkedList<Line>(*llp2);
    
    // assignment operator cases
    *llp4 = ll3; // smaller list onto larger list
    
    D::printDebugInfo(*llp4, 
            "llp4 after assignment operator with a one element list ll3 ");
    
    *llp4 = ll1; // empty list onto larger list   
    D::printDebugInfo(*llp4, 
            "llp4 after assignment operator with an empty list llp1 ");
    
    *llp4 = *llp2; // larger list onto smaller list    
    D::printDebugInfo(*llp4, 
            "llp4 after assignment operator with a larger list llp2 ");
    
    // removal
    // llp4->remove(5); // fails
    llp4->remove(4);
    std::cout << "the list should now have 3 nodes, it has: " 
        << llp4->size() << std::endl;
    
    // bye bye
    delete llp2;
    delete llp4;
}
