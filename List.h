
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
    void deleteNode(type search);
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
  Outputs: None
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
  Outputs: None
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
  Outputs: None
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
  Function deleteNode(type search)
  Descrition:
  Inputs: 'search', is the Node that is to be deleted
  Outputs: None
*/
template <class type>
void List<type>::deleteNode(type search) {

  if(Head->data == search) {
    Node<type> *delPtr = Head;

    if(Head == Tail)
      Head = Tail = 0;
    else
      Head = Head->next;

    delete delPtr;
  }
  else if(Tail->data == search) {
    Node<type> *delPtr = Tail;
    Node<type> *p = Head;

    while(p->next != Tail) {
      p = p->next;
    }

    Tail = p;
    p->next = 0;

    delete delPtr;
  }
  else {
    Node<type> *p = Head;

    while([p->next->data != search) {
        p = p->next;
    }

    Node<type> *delPtr = p->next;
    p->next = p->next->next;
    delete delPtr;
  }
}



/*
  Function findNode(type search)
  Descrition: Will search for a Node and will return it's data member if it
  exists or it will return NULL
  Inputs: search', is the Node that is to be found
  Outputs: return the node if found, or it will return NULL
*/
template <class type>
type List<type>::findNode(type search) {

  Node<type> *p = Head;

  while(p->next != search) {
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
template <class type>
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
template <class type>
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
template <class type>
bool List<type>::isEmpty() {

  if(Head == NULL)
    return true;
  else
    return false;
}

#endif
