#ifndef ENV_H_
#define ENV_H_

#include <list>
#include <map>
#include <string>

#include "Absyn.H"

#include "FunType.H"
#include "TypeException.H"

using namespace std;

class Env {

public:
	
  Type* lookupVar(Id id);
  FunType* lookupFun(Id id);
  void updateVar(Id id, Type* ty);
  void updateFun(Id id, FunType* func);

private:
  map<Id, FunType*> m_fun_context;
  list<map<Id, Type*> > m_context;
};

#endif
