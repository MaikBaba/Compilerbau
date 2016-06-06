#include <list>
#include <unordered_map>
#include <string>

#include "Type.H"
#include "FunType.H"

class Env {
public:
	std::unordered_map <std::string, FunType> signatures;
	std::list<std::unordered_map<std::string, Type> contexts;

  Type lookupVar(String id);
  FunType lookupFun(String id);
  void updateVar(String id, Type ty); 
  void updateFun(String id, FunType f);
       
}