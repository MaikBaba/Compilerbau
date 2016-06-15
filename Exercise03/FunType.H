#ifndef FUNTYPE_H_
#define FUNTYPE_H_

#include <list>
#include <string>

#include "Absyn.H"

#include "BasicType.H"

using namespace std;

class FunType {
  public:
  	BasicType getFunReturnType() {return fun_type;}
  private:
	list<BasicType> fun_args;
    BasicType fun_type;
};

#endif
