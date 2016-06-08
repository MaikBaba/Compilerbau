#include <list>
#include <unordered_map>
#include <map>

#include "string"
#include "Type.H"
#include "Absyn.H"
#include "FunType.H"

using namespace std;

class Env {

public:
	
  Type& lookupVar(string id);
  FunType lookupFun(string id);
  void updateVar(string id, Type& ty);
  void updateFun(string id, FunType& func);

private:
  unordered_map <string, FunType> m_fun_context;
  list<unordered_map<string, Type&>> m_context;

};
