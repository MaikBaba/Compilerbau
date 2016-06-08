#include <list>
#include <string>

#include "Absyn.H"

#include "BasicType.H"

using namespace std;

class FunType {
  public:
    Id fun_id;
	list<Type*> fun_args;
    Type* fun_type;
};
