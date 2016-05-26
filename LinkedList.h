#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdexcept>
#include <string>
#include "Line.h"

// since we're usign templates, destructors can't be virtual
// not made to be a base class...
template<typename T>
class LinkedList{
  private:
    //template<typename T>
    class ListNode{
      private:
        T data;
        ListNode * prev;//{nullptr};
        ListNode * next;//{nullptr};

      public:
        ListNode(const T& t = T(), ListNode * p = nullptr, ListNode * n = nullptr):
          data{t},
          prev{p},
          next{n}{}

        const T& getData(){
            return data;
        }

        // this seems unsafe, is it?
        ListNode * getPrev() const {
            return prev;
        }

        ListNode * getNext() const {
            return next;
        }

        void setData(const T & t) {
            data = t;
        }
        void setPrev(ListNode * p) {
            prev = p;
        }
        void setNext(ListNode * n) {
            next = n;
        }
    }; // class ListNode

    int theSize{0};
    ListNode * head{new ListNode()};
    ListNode * tail{new ListNode()};

  public:
    LinkedList();
    ~LinkedList(); // can't do virtual since it's a template
    LinkedList(const LinkedList &);
    LinkedList & operator=(const LinkedList &);
    void push_front(const T &);
    void push_back(const T &);
    void pop_front();
    void pop_back();
    int size() const;
    bool empty() const;
    void insert(const T &, int);
    void remove(int);
    void print(int);
  private:
    void checkIndex(int) const;
};

#include "LinkedList.cpp"

#endif

