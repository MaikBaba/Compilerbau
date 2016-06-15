#ifndef FUNTYPE_H_
#define FUNTYPE_H_

#include <list>
#include <string>

#include "Absyn.H"

#include "BasicType.H"

using namespace std;

class FunType {
  public:
	list<BasicType> fun_args;
    BasicType fun_type;
};

#endif
