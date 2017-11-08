/*
  Function
  Descrition:
  Inputs:
  Outputs:
*/

#ifndef LIST
#define LIST

template <class type>
struct Node {
  type data;
  Node *next;
};


template <class type>
class List {
  private:
    Node<type> *Head;
    Node<type> *Tail;

  public:
    List();
    void addToFront(type value);
    void addToRear(type value);
    void insert(type search, type value);

    type findNode(type search);
    type getFront();
    type getRear();
    bool isEmpty();

};


/*
  Function List()
  Descrition: Default constructor, sets Head and Tail pointer to 0
  Inputs: None
  Outputs: None
*/
template <class type>
List<type>::List()
  : Head(0), Tail(0)
{
}


/*
  Function addToFront(type value)
  Descrition:
  Inputs:
  Outputs:
*/
template <class type>
void List<type>::addToFront(type value) {

  Node<type> *n = new Node<type>;
  n->data = value;

  if(Head == 0) {
    Head = Tail = n;
  }
  else {
    n->next = Head;
    Head = n;
  }
}


/*
  Function addToRear(type value)
  Descrition:
  Inputs:
  Outputs:
*/
template <class type>
void List<type>::addToRear(type value) {

  Node<type> *n = new Node<type>;
  n->data = value;

  if(Head == 0) {
    Head = Tail = n;
  }
  else {
    Tail->next = n;
    Tail = n;
  }
}


/*
  Function insert(type search ,type value)
  Descrition:
  Inputs:
  Outputs:
*/
template <class type>
void List<type>::insert(type search ,type value) {

  Node<type> *p = Head;

  while(p->data != search) {
    p = p->next;
  }

  Node<type> *n = new Node<type>;
  n->data = value;
  n->next = p->next;
  p->next = n;
}


/*
  Function findNode(type search)
  Descrition:
  Inputs:
  Outputs:
*/
type List<type>::findNode(type search) {

  Node<type> *p = Head;

  while(p->data != search) {
    p = p->next;

    if(p == NULL)
      return NULL;
    else if(p->data == search)
        return p->data;
  }

  return NULL;
}


/*
  Function getFront()
  Descrition: Returns the Node that the Head pointer points to
  Inputs: None
  Outputs: Either NULL is list is empty or the data at the Head of the list
*/
type List<type>::getFront() {

  if(isEmpty())
    return NULL;
  else
    return Head->data;
}


/*
  Function getRear()
  Descrition: Returns the Node that the Tail pointer points to
  Inputs: None
  Outputs: Either NULL is list is empty or the data at the Tail of the list
*/
type List<type>::getRear() {

  if(isEmpty())
    return NULL;
  else
    return Tail->data;
}


/*
  Function isEmpty()
  Desciption: Returns true or false based on list being empty or not
  Inputs: None
  Outputs: True if Head pointer has no data, false if Head pointer has data
*/
bool List<type>::isEmpty() {

  if(Head == NULL)
    return true;
  else
    return false;
}

#endif
