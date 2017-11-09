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
    RPN

    void calculate();
    void removeSpace(string &str);
    type getAnswer();

};


template <class type>
RPN<type>::RPN() {
  input = "";
}


template <class type>
void RPN<type>::calculate() {

  for (int i = 0; i < token.size(); i++) {
    if(token[i] != "*" || token[i] != "/" || token[i] != "+" || token[i] != "-") {
      this->push(token[i]);
    }
    else {
      type tmp2 = this->peek();
      this->pop();
      type tmp1 = this->peek();
      this->pop();
    }
    if(token[i] == "*") {
      this->push(std::to_string(atof(tmp1.c_str()) * atof(tmp2.c_str())));
    }
    
  }

}


template <class type>
void RPN<type>::removeSpace(string &str) {

  for (int i = 0; i < str.length(); i++) {

    if(str[i] == ' ' && str[i+1] == ' ') {
      str.erase(i,1);
    }
  }
}

template <class type>
type RPN<type>::getAnswer() {
  return this->peek();
}


#endif
