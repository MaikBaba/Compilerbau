#ifndef FUNTYPE_H_
#define FUNTYPE_H_

#include <list>
#include <string>

#include "Absyn.H"

using namespace std;

class FunType {
  public:
    Id fun_id;
	list<Type*> fun_args;
    Type* fun_type;
};

#endif
