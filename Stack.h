#ifndef STACK
#define STACK

#include "List.h"

template <class type>
class Stack : private List<type>
{
  private:

  public:
    void push(type value);
    void pop();
    type peek();
    bool isStackEmpty();

};


/*
  Function push(type value)
  Descrition:
  Inputs: 'value', is the value to be added to the stack
  Outputs: None
*/
template <class type>
void Stack<type>::push(type value) {
    this->addToFront(value);
}


/*
  Function pop()
  Descrition:
  Inputs: None
  Outputs: None
*/
template <class type>
void Stack<type>::pop() {
  type tmp = peek();
  this->deleteNode(tmp);
}


/*
  Function peek()
  Descrition:
  Inputs: None
  Outputs: returns the data in the front of the List
*/
template <class type>
type Stack<type>::peek() {
  return this->getFront();
}


/*
  Function isStackEmpty()
  Descrition:
  Inputs: None
  Outputs: returns true is empty or false if not empty
*/
template <class type>
bool Stack<type>::isStackEmpty() {
  return this->isEmpty();
}

#endif
