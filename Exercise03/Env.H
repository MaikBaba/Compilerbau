#ifndef ENV_H_
#define ENV_H_

#include <list>
#include <map>
#include <string>

#include "Absyn.H"

#include "FunType.H"
#include "BasicType.H"
#include "TypeException.H"

using namespace std;

class Env {

	//TODO all new function

public:

  BasicType lookupVar(Id id);
  BasicType lookupFun(Id id, vector<BasicType>* arglist);
  void updateVar(Id id, BasicType ty);
  void updateFun(Id id, FunType func);
  void addScope();
  void delScope();
  void clearEnv();

private:
  multimap<Id, FunType*> m_fun_context;
  list<map<Id, BasicType>* > m_context;
};

#endif
