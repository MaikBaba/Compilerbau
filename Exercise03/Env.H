#include <list>
#include <map>
#include <string>

#include "Absyn.H"

#include "BasicType.H"
#include "FunType.H"
#include "TypeException.H"

using namespace std;

class Env {

public:
	
  BasicType lookupVar(Id id);
  FunType lookupFun(Id id);
  void updateVar(Id id, Type* ty);
  void updateFun(Id id, FunType* func);

private:
  map<Id, FunType*> m_fun_context;
  list<map<Id, Type*> > m_context;
};
