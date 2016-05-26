//#include "LinkedList.h"

template<typename T>
LinkedList<T>::LinkedList(){
    head->setNext(tail);
    tail->setPrev(head);
}

template<typename T>
LinkedList<T>::~LinkedList(){ // can't do virtual since it's a template
    ListNode * temp = head;
    while (temp->getNext() != nullptr) {
        temp = temp->getNext();
        delete temp->getPrev();
    }
    temp = nullptr;
    delete tail;
    // head and tail need not be set to nullptr since they will be no more
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> & rhs){
    head->setNext(tail);
    tail->setPrev(head);
    ListNode * tempL = head;
    ListNode * tempR = rhs.head;
    for (int i = 0; i < rhs.theSize; i++) {
        tempR = tempR->getNext();
        ListNode * newNode = new ListNode(tempR->getData(), 
                tempL, tempL->getNext());
        tempL->getNext()->setPrev(newNode);
        tempL->setNext(newNode);
        tempL = tempL->getNext();
        theSize++;
    } 
}

template<typename T>
LinkedList<T> & LinkedList<T>::operator=(const LinkedList<T> & rhs){
    ListNode * tempL = head;
    ListNode * tempR = rhs.head;
    // copy the minimum of rhs.theSize and size to minimize deleting and creating
    for (int i = 0; (i < theSize) && (i < rhs.theSize); i++) {
        tempL = tempL->getNext();
        tempR = tempR->getNext();
        tempL->setData(tempR->getData());
    }
    // now if this is a longer list, we need to delete
    for (int j = 0; j < (theSize - rhs.theSize); j++){
        tempL = tempL->getNext();
        tempL->getPrev()->setNext(tempL->getNext());
        delete tempL;        
    }
    //head->prev->next = head;    
    // but if rhs is longer, create missing nodes
    for (int k = 0; k < (rhs.theSize - theSize); k++) {
        tempR = tempR->next;
        ListNode * newNode = new ListNode(tempR.data, tempL, tail);
        tempL->setNext(newNode);
    }
    // re-attach the tail
    tail->setPrev(tempL);
    theSize = rhs.theSize; 
}

template<typename T>
void LinkedList<T>::push_front(const T & t){
    ListNode * newNode = new ListNode(t, head, head->getNext());
    head->getNext()->setPrev(newNode);
    head->setNext(newNode);
    theSize++;
}

template<typename T>
void LinkedList<T>::push_back(const T & t){
    ListNode * newNode = new ListNode(t, tail->getPrev(), tail);
    tail->getPrev()->setNext(newNode);
    tail->setPrev(newNode);
    theSize++;
}

template<typename T>
void LinkedList<T>::pop_front(){
    checkIndex(1);
    ListNode * temp = head->getNext();
    temp->getNext()->setPrev(head);
    head->setNext(temp->getNext());
    delete temp;
    theSize--;
}

template<typename T>
void LinkedList<T>::pop_back(){
    checkIndex(theSize);
    ListNode * temp = tail->getPrev();
    temp->getPrev()->setNext(tail);
    tail->setPrev(temp->getPrev());
    delete temp;
    theSize--;

}

template<typename T>
int LinkedList<T>::size() const{
    return theSize;
}

template<typename T>
bool LinkedList<T>::empty() const{
    return (theSize == 0);//alternatively head-getNext()==tail
}

// index 0 == head, 1 is first node
template<typename T>
void LinkedList<T>::insert(const T & t, int k){
    if ( !((k == 1) || (k == theSize + 1)) ) {
        checkIndex(k);
    }
    ListNode * temp = head;
    ListNode * newNode;
    int i{0};
    while (i < k) {
        temp = temp->getNext();
        i++;
    }
    newNode = new ListNode(t, temp->getPrev(), temp);
    temp->getPrev()->setNext(newNode);
    temp->setPrev(newNode);
    theSize++;   
}

template<typename T>
void LinkedList<T>::remove(int k)
{
    checkIndex(k);
    ListNode * temp = head;
    int i{0};
    while (i < k) {
        temp = temp->getNext();
        i++;
    }
    temp->getPrev()->setNext(temp->getNext());
    temp->getNext()->setPrev(temp->getPrev());
    delete temp;
    theSize--;
}

template<typename T>
void LinkedList<T>::print(int k)
{
    checkIndex(k); 
    ListNode * temp = head;
    int i{0};
    while (i < k) { //TODO 0-index or 1 index, see also conditions above
        temp = temp->getNext();
        i++;
    }
    std::cout << "(" << k << ")" << temp->getData();
}
 
template<typename T>
void LinkedList<T>::checkIndex(int index) const{
    if ((index < 1) || (index > theSize)) {
        std::string msg = "bad index " + std::to_string(index) 
            + ": index out of range";
        throw std::out_of_range(msg);
    }
}
