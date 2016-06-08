#include <list>
#include <string>

#include "Absyn.H"

#include "BasicType.H"

class FunType {
  public:
    Id fun_id;
	std::list<BasicType*> fun_args;
    BasicType* fun_type;
};
