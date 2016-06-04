/*
 * Assignennt 1, COMP 5421, summer 2016  
 * Federico O'Reilly Regueiro 40012304
 * Concordia University
 *
 * A templated doubly linkedList Class header file
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdexcept>
#include <string>
#include "Line.h"

// since we're usign templates, destructors can't be virtual
// not made to be a base class...
template<typename T>
class LinkedList{
// need to be able to access node data for printing in testing (debug) mode
#ifdef NDEBUG
  private:
#else
  public:
#endif
    //template<typename T>
    class ListNode{
      public:
        T data; /**< Data contained in the node*/
        ListNode * prev; /**< Pointer to the previous node*/
        ListNode * next; /**< Pointer to the next node*/

        /**
         * Default constructor (given by default values) which acts also as
         * @param t is node data <T>, defaulted to default data <T> constructor
         * @param p pointer to previous node
         * @param n pointer to next node
         */
        ListNode(const T& t = T(), ListNode * p = nullptr, ListNode * n = nullptr):
          data{t},
          prev{p},
          next{n}{}
    }; // class ListNode

    int theSize{0};  /**< Size of the list, initially set to 0*/
    ListNode * head{new ListNode()}; /**< head sentinel node */
    ListNode * tail{new ListNode()}; /**< tail sentinel node */


  public:
    /**
     * Default constructor.
     * Produces an empty list with it's two sentinel nodes.
     */ 
    LinkedList();

    /**
     * Dtor.
     * Since this is a template class, it cannot have a virtual destructor.
     */
    ~LinkedList(); 

    /**
     * Copy ctor.
     * Produces, via deep copying, a copy of a given LinkedList.
     * @param ll is a reference to the LinkedList to be copied
     */ 
    LinkedList(const LinkedList &);


    /**
     * Assignment operator.
     * Turns *this, via deep copying,  into a copy of a given LinkedList.
     * @param ll is a reference to the LinkedList to be copied
     */ 
    LinkedList & operator=(const LinkedList &);

    /**
     * Push element to the front of the LinkedList.
     * @param t is a reference to the element being pushed into the list.
     */
    void push_front(const T &);


    /**
     * Push element to the back of the LinkedList.
     * @param t is a reference to the element being pushed into the list.
     */
    void push_back(const T &);

    
    /**
     * Remove element from the front of the LinkedList.
     */
    void pop_front();


    /**
     * Remove element from the back of the LinkedList.
     */
    void pop_back();

    /**
     * Returns the size of the list.
     */
    int size() const;

    /**
     * Return true if the list is empty.
     */
    bool empty() const;

    /**
     * Insert an element into a certain position.
     * Notice the list is 1-indexed, where the first element's index is
     * 1 and not 0.
     * @param t is a reference to the element being inserted.
     * @param k is an index to the position of insertion. 
     */
    void insert(const T &, int);


    /**
     * Remove an element from a certain position.
     * Notice the list is 1-indexed, where the first element's index is
     * 1 and not 0.
     * @param k is an index to the position of insertion. 
     */
    void remove(int);


    /**
     * Print an element at a certain position.
     * Notice the list is 1-indexed, where the first element's index is
     * 1 and not 0.
     * @param k is an index to the position of insertion. 
     */
    void print(int);
  private:
    /**
     * Helper function to ensure proper indexing.
     * Throws an exception if the index given is out of bounds.
     * @param k is the index to check for validity.
     */ 
    void checkIndex(int) const;
};

#include "LinkedList.cpp"

#endif

