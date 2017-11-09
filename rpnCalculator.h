#ifndef RPNCALCULATOR
#define RPNCALCULATOR


#include "Stack.h"
#include <cctype>
#include <iostream>
#include <sstream>
#include <vector>
using std::string;
using std::stringstream;
using std::vector;

template <class type>
class RPN : public Stack<type> {
  private:
    type input;
    vector<string> token;

  public:
    RPN();

};


template <class type>
RPN<type>::RPN() {
  input = "";
}

#endif
