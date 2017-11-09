#ifndef QUEUE
#define QUEUE

#include "List.h"

template <class type>
class Queue : private List<type> {

  private:

  public:
    void enqueue(type value);
    void dequeue();
    type peek();
    bool isQueueEmpty();
};

/*
  Function: enqueue(type value)
  Descrition: Adds the data memeber to the back of the Queue which is held by
  the List
  Inputs: 'value', is the data member to be added to the back
  Outputs: None
*/
template <class type>
void Queue<type>::enqueue(type value) {
  this->addToRear(value);
}


/*
  Function: dequeue()
  Descrition: Removes the first member of the Queue, which is the first Node of
  the List
  Inputs: None
  Outputs: None
*/
template <class type>
void Queue<type>::dequeue() {
  type tmp = peek();
  this->deleteNode(tmp);
}


/*
  Function: peek()
  Descrition:
  Inputs: None
  Outputs: Returns the first data member in the front of the Queue
*/
template <class type>
type Queue<type>::peek() {
  return this->getFront();
}


/*
  Function: isQueueEmpty()
  Descrition: Checks if Queue is empty or not and retus true or false based on
  that check.
  Inputs: None
  Outputs: Returns true or false based on whether Queue is empty or not
*/
template <class type>
bool Queue<type>::isQueueEmpty() {
  return this->isEmpty();
}

#endif
