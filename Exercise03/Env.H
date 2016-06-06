#include <list>
#include <map>
#include <string>

#include "Type.H"
#include "FunType.H"

class Env {
  public:
  	std::map <std::string, FunType> signature;
  	std::list <std::map<std::string, Type>> contexts;

    Type lookupVar(String id);
    FunType lookupFun(String id);
    void updateVar(String id, Type ty);
}