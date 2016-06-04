/*
 * Assignennt 1, COMP 5421, summer 2016  
 * Federico O'Reilly Regueiro 40012304
 * Concordia University
 *
 * A templated doubly linkedList Class implementation file
 */


template<typename T>
LinkedList<T>::LinkedList(){
    head->next = tail;
    tail->prev = head;
}

template<typename T>
LinkedList<T>::~LinkedList(){ // can't do virtual since it's a template
    ListNode * temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
        delete temp->prev;
    }
    temp = nullptr;
    delete tail;
    // head and tail need not be set to nullptr since they will be no more
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> & rhs){
    head->next = tail;
    tail->prev = head;
    ListNode * tempL = head;
    ListNode * tempR = rhs.head;
    for (int i = 0; i < rhs.theSize; i++) {
        tempR = tempR->next;
        ListNode * newNode = new ListNode(tempR->data, 
                tempL, tempL->next);
        tempL->next->prev = newNode;
        tempL->next = newNode;
        tempL = tempL->next;
        theSize++;
    } 
}

template<typename T>
LinkedList<T> & LinkedList<T>::operator=(const LinkedList<T> & rhs){

    if(this != &rhs){ // avoid self-assignment
        ListNode * tempL = head;
        ListNode * tempR = rhs.head;
        // copy the minimum of rhs.theSize and size to minimize
        // deleting and creating
        for (int i = 0; (i < theSize) && (i < rhs.theSize); i++) {
            tempL = tempL->next;
            tempR = tempR->next;
            tempL->data = tempR->data;
        }
        // now if this is a longer list, we need to delete
        for (int j = 0; j < (theSize - rhs.theSize); j++){
            tempL = tempL->next;
            tempL->prev->next = tempL->next;
            delete tempL;        
        }
        //head->prev->next = head;    
        // but if rhs is longer, create missing nodes
        for (int k = 0; k < (rhs.theSize - theSize); k++) {
            tempR = tempR->next;
            ListNode * newNode = new ListNode(tempR->data, tempL, tail);
            tempL->next = newNode;
            tempL = newNode;
        }
        // re-attach the tail
        tail->prev = tempL;
        theSize = rhs.theSize;
    }
    return * this; 
}

template<typename T>
void LinkedList<T>::push_front(const T & t){
    ListNode * newNode = new ListNode(t, head, head->next);
    head->next->prev = newNode;
    head->next = newNode;
    theSize++;
}

template<typename T>
void LinkedList<T>::push_back(const T & t){
    ListNode * newNode = new ListNode(t, tail->prev, tail);
    tail->prev->next = newNode;
    tail->prev = newNode;
    theSize++;
}

template<typename T>
void LinkedList<T>::pop_front(){
    checkIndex(1);
    ListNode * temp = head->next;
    temp->next->prev = head;
    head->next = temp->next;
    delete temp;
    theSize--;
}

template<typename T>
void LinkedList<T>::pop_back(){
    checkIndex(theSize);
    ListNode * temp = tail->prev;
    temp->prev->next = tail;
    tail->prev = temp->prev;
    delete temp;
    theSize--;
}

template<typename T>
int LinkedList<T>::size() const{
    return theSize;
}

template<typename T>
bool LinkedList<T>::empty() const{
    return (theSize == 0);//alternatively head->next==tail
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
        temp = temp->next;
        i++;
    }
    newNode = new ListNode(t, temp->prev, temp);
    temp->prev->next = newNode;
    temp->prev = newNode;
    theSize++;   
}

template<typename T>
void LinkedList<T>::remove(int k)
{
    checkIndex(k);
    ListNode * temp = head;
    int i{0};
    while (i < k) {
        temp = temp->next;
        i++;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    theSize--;
}

template<typename T>
void LinkedList<T>::print(int k)
{
    checkIndex(k); 
    ListNode * temp = head;
    int i{0};
    while (i < k) { 
        temp = temp->next;
        i++;
    } 
    std::cout << temp->data;
}
 
template<typename T>
void LinkedList<T>::checkIndex(int index) const{
    if ((index < 1) || (index > theSize)) {
        std::string msg = "bad index " + std::to_string(index) 
            + ": index out of range";
        throw std::out_of_range(msg);
    }
}
