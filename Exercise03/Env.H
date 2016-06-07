#include <list>
#include <unordered_map>

#include "string"
#include "Type.H"
#include "FunType.H"

using namespace std;

class Env {

public:
	
  Type lookupVar(String id);
  FunType lookupFun(String id);
  void updateVar(String id, Type ty); 
  void updateFun(String id, FunType* func);

private:
  unordered_map <string, FunType> fun_context;
  list<unordered_map<string, Type>> context;

}