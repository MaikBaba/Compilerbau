#include <list>
#include <unordered_map>
#include <map>

#include "string"
#include "BasicType.H"
#include "Absyn.H"
#include "FunType.H"

using namespace std;

class Env {

public:
	
  BasicType lookupVar(string id);
  BasicType lookupFun(FunType*);
  void updateVar(string id, BasicType* ty);
  void updateFun(string id, FunType* func);

private:
  unordered_map <string, FunType> m_fun_context;
  list<unordered_map<string, BasicType> > m_context;

};
